#ifndef WOLFETFACTORY_H
#define WOLFETFACTORY_H

#ifdef WIN32
#include "../stdafx.h"
#endif

#include "parserfactory.h"
#include "wolfetparser.h"


class WolfETFactory : public ParserFactory
{
	public:
		WolfETFactory() {};
		WolfETParser* createParser(const string&) const;
		virtual ~WolfETFactory();
};
	

#endif

