#ifndef PARSER_H
#define PARSER_H

#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>


using namespace std;

class Parser
{
	public:
		Parser(const string&);
		virtual ~Parser();
		virtual void read_file(string) = 0;
		virtual void write_file(string) = 0;
		virtual void parse_file() = 0;
		virtual void parse_line(string) = 0;
		virtual bool search_for(string) = 0;
		virtual int get_keyword(string) = 0;
		virtual string get_keyword_string(int) = 0;

	protected:
		string filename;
};


#endif

