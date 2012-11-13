
#include <boost/shared_ptr.hpp>
#include <boost/program_options.hpp>
#include <boost/make_shared.hpp>
#include <ulimit.h>
#include <limits>


#include "ast.h"
#include "parser.hpp"


extern FILE *yyin;
extern StatementsAST *programBlock;

namespace po = boost::program_options;

static void generate(StatementsAST * ast);

int main(int argc, char **argv)
{
	std::string outfilename;
	po::options_description desc("qvod_crack options");
	desc.add_options()
		("-c", "compile only")
		("-ir", "generate llvm-IR and stop")
		("outfile,o", po::value<std::string>(&outfilename), "set outputname")
		;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);
	
	// usage llvmqbc input.bas -o a.out
	// ./a.out
	yyin = fopen("../test.bas","r");
	if(!yyin)
	{
		printf("test.bas open failed\n");
		return 1;
	}
	//std::ifstream input();
	yyparse();

	//TODO 从 programBlock 生成 llvm IR

	generate(programBlock);
	
	return 0;
}

// generate llvm IR
static void generate(StatementsAST * ast)
{
	for( std::list< StatementASTPtr >::iterator it = ast->begin();
	    it != ast->end();
		it ++ )
	{
		
	}
	
	
}