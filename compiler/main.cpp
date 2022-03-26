
#include "qbc.h"

#include <boost/format.hpp>
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <boost/filesystem.hpp>
namespace fs=boost::filesystem;
#include <llvm/InitializePasses.h>
#include <llvm/LinkAllPasses.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetParser.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/MC/TargetRegistry.h>
#include "llvm/Target/TargetOptions.h"
#include "llvm/Target/TargetMachine.h"

#include <llvm/Pass.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/LegacyPassManager.h>

#include "ast.hpp"
#include "parser.hpp"

extern FILE *yyin;
StatementAST * program;

static std::list<std::string> argv_getinputfiles(int argc, char **argv)
{
	std::list<std::string> ret;

	for(int i = 1 ; i < argc ; i++){
		if( argv[i][0] != '-' && fs::exists(argv[i]) )
			ret.push_back(argv[i]);
	}
	return ret;
}

// generate llvm IR
static void generateIR(StatementAST * ast , llvm::Module * module )
{
	ASTContext ctx;
	ctx.module = module;

	CodeBlockAST	gloablblock;
	ctx.codeblock = &gloablblock;
	//ctx.astfunc = ;
	((StatementAST*)(ast))->Codegen(ctx);
}

static int generateobj(boost::shared_ptr<llvm::ToolOutputFile> Out, llvm::Module * module)
{
	llvm::legacy::PassManager PM;

	llvm::TargetOptions Options;

	std::string Err;

	llvm::Triple TheTriple(module->getTargetTriple());
	if (TheTriple.getTriple().empty())
		TheTriple.setTriple(llvm::sys::getDefaultTargetTriple());

	const llvm::Target* TheTarget = llvm::TargetRegistry::lookupTarget(TheTriple.getTriple(), Err);

	std::string MCPU,FeaturesStr;

	llvm::TargetMachine * machineTarget =
		TheTarget->createTargetMachine(TheTriple.getTriple(), MCPU, FeaturesStr, Options, llvm::Reloc::Model::PIC_);

	// Figure out where we are going to send the output...

    if (machineTarget->addPassesToEmitFile(PM, Out->os(), nullptr, llvm::CodeGenFileType::CGFT_ObjectFile))
	{
      std::cerr << " target does not support generation of this"     << " file type!\n";
      return 1;
    }

	PM.run(*module);
	return 0;
}

namespace qbc {
extern llvm::LLVMContext getGlobalContext;
}

int main(int argc, char **argv)
{
	std::string outfilename;
	po::options_description desc("qvod_crack options");
	desc.add_options()
		("help,h", "display this help")
		(",c", "compile only")
		("ir", "generate llvm-IR and stop")
		("outfile,o", po::value<std::string>(&outfilename), "set outputname")
		;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
        std::cout << desc;
        return 0;
    }

    std::list<std::string> inputs = argv_getinputfiles(argc,argv);
	if(inputs.empty()){
		std::cerr <<  "no input file" << std::endl;
		return 1;
	}

	std::string input = inputs.begin()->c_str();

	// usage llvmqbc input.bas -o a.out
	// ./a.out
	std::cout << "openning: " << input << std::endl;
	yyin = std::fopen(input.c_str(),"r");

	if(!yyin)
	{
		printf("open %s failed\n",input.c_str());
		return 1;
	}

	qb::parser parser;

	parser.parse();

	std::cout << "parse done, no errors, generating llvm IR..." << std::endl;

	// Initialize targets first, so that --version shows registered targets.
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmPrinters();
	llvm::InitializeAllAsmParsers();
	llvm::InitializeAllAsmParsers();

	// 如果没有指定输出文件路径, 设置输出文件的路径为输入文件相同的路径下.
	if(outfilename.empty())
		outfilename = (fs::path(input).parent_path() / fs::basename(fs::path(input))).string();

	llvm::Module *module = new llvm::Module( fs::basename(fs::path(input)).c_str(), qbc::getGlobalContext);
	generateIR(program,module);

	// ir to generate llvm IR
	if(vm.count("ir")){
//		module->dump();
		return 0;
	}

#if _WIN32
	std::string outobjname = outfilename + ".obj";
#else
	std::string outobjname = outfilename + ".o";
#endif
	std::error_code Err;

	boost::shared_ptr<llvm::ToolOutputFile> Out(new llvm::ToolOutputFile(outobjname.c_str(), Err, llvm::sys::fs::OF_None));

	if(generateobj(Out, module)==0)
		printf("======== object file writed to %s ===========\n", outobjname.c_str());

	if(!vm.count("-c"))
	{
		// compile to excuteable
#if _WIN32
		std::string cmd = boost::str(boost::format("link.exe /out:%s %s msvcrt.lib")
			% std::string(outfilename + ".exe") %  outobjname );
#else
		// invoke  gcc
		boost::filesystem::path libdir = fs::path(argv[0]).parent_path().string();
		boost::filesystem::path libbrt_a = libdir / "libbrt.a";
		std::string linker_commandline = getenv("CC") ? getenv("CC") : "cc";
		std::string cmd = boost::str(boost::format("%s -fuse-ld=lld -o %s %s %s") % linker_commandline
							% outfilename %  (outfilename + ".o") % libbrt_a.string());
#endif
		printf("run linker: %s\n", cmd.c_str());
		if(std::system(cmd.c_str())==0)
			Out->keep(); // keep the file if linker runs fine

	} else {
		// no delete obj file
		Out->keep();
	}

	return 0;
}
