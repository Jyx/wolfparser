#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>
#include "parserfactory.h"
#include "wolfetfactory.h"
#include "debug.h"


ParserFactory* ParserFactory::getFactory(const string& s)
{
	
	if (s.find_first_of("wolfet") != string::npos)
	{
		string tmpmess = "Found wolfet, returning WolfETFactory";
		DPRINT(tmpmess);
		return new WolfETFactory();
	} 
	else 	
		return new WolfETFactory();
}

ParserFactory::~ParserFactory() {}

