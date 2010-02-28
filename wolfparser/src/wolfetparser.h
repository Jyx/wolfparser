#ifndef WOLFETPARSER_H
#define WOLFETPARSER_H

#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "parser.h"


using namespace std;


class WolfETParser : public Parser
{
	public:
		WolfETParser(const string&);
		virtual ~WolfETParser();

		void read_file(string);
		void write_file(string);
		void parse_file();
		void parse_line(string);
		bool search_for(string);
		int get_keyword(string);
		string get_keyword_string(int);

		enum keyword {BIND, BOT_, CF_, CG_, CL_, COM_, CON_, DEMO_, G_, IN_, JOY_,
			MATCH_, MISC_, M_, R_, SERVER_, SV_, S_, TEAM_, UI_, VM_, VOTE_, ALIAS};

			typedef multimap<int, string>::const_iterator MI;

	private:
			bool compare_lines(string, string);
			multimap<int, string> wm;
			vector<string> wolf_file;

};

struct case_insensitive : public binary_function<string, string, bool>
{
	bool operator()(string x, string y);
};

#endif
