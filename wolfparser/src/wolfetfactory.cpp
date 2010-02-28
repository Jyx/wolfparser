#ifdef WIN32
#include "../stdafx.h"
#endif

#include "wolfetfactory.h"


WolfETParser* WolfETFactory::createParser(const string& s) const
{
	return new WolfETParser(s);
}

WolfETFactory::~WolfETFactory() {}
	
