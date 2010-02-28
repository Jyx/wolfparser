// wolfparser.cpp : Defines the entry point for the console application.
//

#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <cassert>
#include <string>
#include "debug.h"
#include "utilities.h"
#include "parserfactory.h"
#include "parser.h"

using namespace std;

int main(int argc, char* argv[])
{
	use(&argc);
	use(&argv);

	ParserFactory *pf = ParserFactory::getFactory("wolfet");
	Parser *p = pf->createParser("etconfig.cfg");
	p->read_file("etconfig.cfg");
	p->parse_file();
	p->write_file("etconfig.cfg.parsed");
	delete pf;
	delete p;
	
	return EXIT_SUCCESS;
}

