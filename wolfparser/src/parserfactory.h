#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#ifdef WIN32
#include "../stdafx.h"
#endif

#include "parser.h"

class Parser;
class ParserFactory
{
	public:
		virtual Parser* createParser(const string&) const = 0;
		static ParserFactory* getFactory(const string&);
		virtual ~ParserFactory();
};

#endif

