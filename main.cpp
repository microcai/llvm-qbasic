
#include <boost/shared_ptr.hpp>


#include <boost/program_options.hpp>
#include <boost/make_shared.hpp>
#include "ast.h"
#include "parser.hpp"

namespace po = boost::program_options;

int main(int argc, char **argv)
{
	std::string outfilename;
	po::options_description desc("qvod_crack options");
	desc.add_options()
		("-c", "compile only")
		("-ir", "generate llvm-IR and stop")
		("outfile,o", po::value<std::string>(&outfilename), "set outputname")
		;

	AST *t;
	
	// usage llvmqbc input.bas -o a.out
	// ./a.out
	//std::ifstream input();
	yyparse();
//    std::cout << "Hello, world!" << std::endl;
    return 0;
}
