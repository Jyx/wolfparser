#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>
#include <fstream>
#include "utilities.h"


using namespace std;

/* Dummy to disable warning about unused variabled */
void use(const void*) {}

string to_lower(string s)
{
	for (int i = 0; i < static_cast<int>(s.length()); i++)
	{
		string tmp = "";
		if (s.at(i) >= 'A' && s.at(i) <= 'W')
			s[i] = s[i] - 'A' + 'a';
	}
	return s;
}


