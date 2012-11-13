#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <boost/filesystem.hpp>
namespace fs=boost::filesystem;
#include <llvm/Support/IRBuilder.h>

#include "ast.h"
#include "parser.hpp"


extern FILE *yyin;
extern AST *programBlock;

static void generate(AST * ast);

static std::list<std::string> argv_getinputfiles(int argc, char **argv)
{
	std::list<std::string> ret;
	
	for(int i = 1 ; i < argc ; i++){
		if( argv[i][0] != '-' && fs::exists(argv[i]) )
			ret.push_back(argv[i]);
	}
	return ret;
}

int main(int argc, char **argv)
{
	std::string outfilename;
	po::options_description desc("qvod_crack options");
	desc.add_options()
		(",c", "compile only")
		("ir", "generate llvm-IR and stop")
		("outfile,o", po::value<std::string>(&outfilename), "set outputname")
		("help,h)" , "display this help")
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
	//std::ifstream input();
	yyparse();

	//TODO 从 programBlock 生成 llvm IR

	if(outfilename.empty()){
		//选择一个
		outfilename = fs::basename( fs::path(input)) + ".o";
	}

	AST::module = new llvm::Module( outfilename.c_str(), llvm::getGlobalContext());


	generate(programBlock);

	//compile to excuteable if -c not specified
	if(vm.count("c")){
		// write to object file
	}else{
		// compile to excuteable		
	}
	return 0;
}

// generate llvm IR
static void generate(AST * ast)
{
	//首先生成全局可用的外部辅助函数
	llvm::IRBuilder<> builder(llvm::getGlobalContext());

	//开始生成代码
	do{
		ast->Codegen();
		ast = ast->next.get();
	}while(ast);
}