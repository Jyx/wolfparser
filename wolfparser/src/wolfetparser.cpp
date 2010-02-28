#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include "wolfetparser.h"
#include "debug.h"
#include "utilities.h"
#include "parser.h"

using namespace std;

WolfETParser::WolfETParser(const string& filename) : Parser(filename)
{
}

WolfETParser::~WolfETParser() {}

void WolfETParser::read_file(string filename) 
{ 
	DPRINTF(filename, "WolfETParser::read_file"); 
	ifstream inf(filename.c_str());
	if (!inf)
	{
		cerr << "Couldn't open file: " << filename << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(inf, line)) 
	{
		if (!line.empty())
			wolf_file.push_back(line);
		debuglog(line);
	}
} 

void WolfETParser::write_file(string filename)
{ 
	DPRINTF(filename, "WolfETParser::write_file"); 
	int actual_command = -1;
	ofstream outf(filename.c_str());
	if (!outf)
	{
		cerr << "Couldn't save to file: filename" << endl;
		exit(EXIT_FAILURE);
	}
	
	for (MI it = wm.begin(); it != wm.end(); ++it)
	{
		actual_command = it->first;
		vector<string> sortedvect;
		while (it->first == actual_command && it != wm.end())
		{
			sortedvect.push_back(it->second);
			++it;
		}
		--it; // Because we get one increment to much when while ends
		if (actual_command != ALIAS)
			sort(sortedvect.begin(), sortedvect.end(), case_insensitive());
		
		outf << "\n" << get_keyword_string(actual_command) << "\n" << endl;
		copy(sortedvect.begin(), sortedvect.end(), ostream_iterator<string>(outf, "\n"));
	}
	outf.close();
}

bool WolfETParser::compare_lines(string a, string b)
{
	return to_lower(a) == to_lower(b);
}

void WolfETParser::parse_file()
{ 
	DPRINT("WolfETParser::parse_file"); 
	// FIXME Använd iterator istället
	for (int i = 0; i < static_cast<int>(wolf_file.size()); ++i)
	{
		int ct = get_keyword(to_lower(wolf_file[i]));
		pair<int, string> p(ct, wolf_file[i]);
		wm.insert(p);
	}
}

void WolfETParser::parse_line(string line)
{ 
	DPRINTF(line, "WolfETParser::parse_line");
}

bool WolfETParser::search_for(string word)
{
	DPRINTF(word, "WolfETParser::search_for");
	return false;
}

int WolfETParser::get_keyword(string line)
{
	DPRINTF(line, "WolfETParser::get_keyword");
	keyword kw = MISC_;
	if (line.find("alias") != string::npos) 
	{
		kw = ALIAS;
	} 
	else if (line.find("bind") != string::npos) 
	{
		kw = BIND;
	} 
	else if (line.find("com_") != string::npos) 
	{
		kw = COM_;
	}
	else if (line.find("in_") != string::npos) 
	{
		kw = IN_;
	}
	else if (line.find("joy_") != string::npos) 
	{
		kw = JOY_;
	}
	else if (line.find("vm_") != string::npos) 
	{
		kw = VM_;
	}
	else if (line.find("sv_") != string::npos) 
	{
		kw = SV_;
	}
	else if (line.find("cg_") != string::npos) 
	{
		kw = CG_;
	}
	else if (line.find("server_") != string::npos) 
	{
		kw = SERVER_;
	}
	else if (line.find("bot_") != string::npos) 
	{
		kw = BOT_;
	}
	else if (line.find("con_") != string::npos) 
	{
		kw = CON_;
	}
	else if (line.find("cl_") != string::npos) 
	{
		kw = CL_;
	}
	else if (line.find("ui_") != string::npos) 
	{
		kw = UI_;
	}
	else if (line.find("g_") != string::npos) 
	{
		kw = G_;
	}
	else if (line.find("m_") != string::npos) 
	{
		kw = M_;
	}
	else if (line.find("s_") != string::npos) 
	{
		kw = S_;
	}
	else if (line.find("r_") != string::npos) 
	{
		kw = R_;
	}
	else if (line.find("match_") != string::npos) 
	{
		kw = MATCH_;
	}
	else if (line.find("team_") != string::npos) 
	{
		kw = TEAM_;
	}
	else if (line.find("vote_") != string::npos) 
	{
		kw = VOTE_;
	}
	else if (line.find("cf_") != string::npos) 
	{
		kw = CF_;
	}
	else if (line.find("demo_") != string::npos) 
	{
		kw = DEMO_;
	}
	return kw;
}

string WolfETParser::get_keyword_string(int i)
{
	string kw;
	switch(i)
	{
		case(ALIAS):
			kw = "// ====    ALIAS COMMANDS    ====";
			break;
		case(BIND):
			kw = "// ====    BIND COMMANDS    ====";
			break;
		case(R_):
			kw = "// ====    R_ COMMANDS    ====";
			break;
		case(COM_):
			kw = "// ====    COM_ COMMANDS    ====";
			break;
		case(IN_):
			kw = "// ====    IN_ COMMANDS    ====";
			break;
		case(JOY_):
			kw = "// ====    JOY_ COMMANDS    ====";
			break;
		case(VM_):
			kw = "// ====    VM_ COMMANDS    ====";
			break;
		case(SV_):
			kw = "// ====    SV_ COMMANDS    ====";
			break;
		case(CG_):
			kw = "// ====    CG_COMMANDS    ====";
			break;
		case(BOT_):
			kw = "// ====    BOT_ COMMANDS    ====";
			break;
		case(CON_):
			kw = "// ====    CON_ COMMANDS    ====";
			break;
		case(CL_):
			kw = "// ====    CL_ COMMANDS    ====";
			break;
		case(G_):
			kw = "// ====    G_ COMMANDS    ====";
			break;
		case(M_):
			kw = "// ====    M_ COMMANDS    ====";
			break;
		case(S_):
			kw = "// ====    S_ COMMANDS    ====";
			break;
		case(UI_):
			kw = "// ====    UI_ COMMANDS    ====";
			break;
		case(MATCH_):
			kw = "// ====    MATCH_ COMMANDS    ====";
			break;
		case(SERVER_):
			kw = "// ====    SERVER_ COMMANDS    ====";
			break;
		case(TEAM_):
			kw = "// ====    TEAM_ COMMANDS    ====";
			break;
		case(VOTE_):
			kw = "// ====    VOTE_ COMMANDS    ====";
			break;
		case(CF_):
			kw = "// ====    CF_ COMMANDS    ====";
			break;
		case(DEMO_):
			kw = "// ====    DEMO_ COMMANDS    ====";
			break;
		case(MISC_):
			kw = "// ====    MISC COMMANDS    ====";
			break;
		default:
			kw = "";
	}
	return kw;
}

bool case_insensitive::operator()(string x, string y) 
{
	return to_lower(x) < to_lower(y);
}

