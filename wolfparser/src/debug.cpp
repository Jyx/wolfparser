#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include "debug.h"


using namespace std;

/*
 *--------------------------------------------------------------------------------------
 *      Method:  Takes an integer as argument, write it out to a file
 * Description:  
 *--------------------------------------------------------------------------------------
 */
void debuglog(int msg) 
{
    ofstream outf("debug_logg.txt");
    if (!outf)
    {
        cerr << "Coudln't open logfile" << endl;
        return;
    }

#ifdef TIME
    time_t rawtime;
    time ( &rawtime );
    outf << "<-- |DEBUG| --> " << ctime (&rawtime);
    outf << "<-- |DEBUG| --> " << msg << endl;
#else
    outf << "<-- |DEBUG| --> " << msg << endl;
#endif
    outf.close();
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  Takes a string as argument, write it out to a file
 * Description:  
 *--------------------------------------------------------------------------------------
 */
void debuglog(string msg) 
{
    ofstream outf("debug_logg.txt", ios::app);
    if (!outf)
    {
        cerr << "Coudln't open logfile" << endl;
        return;
    }
#ifdef TIME
    time_t rawtime;
    time ( &rawtime );
    outf << "<-- |DEBUG| --> " << ctime (&rawtime);
    outf << "<-- |DEBUG| --> " << msg << endl;
#else
    outf << "<-- |DEBUG| --> " << msg << endl;
#endif
    outf.close();
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  Takes a *char as argument, write it out to a file
 * Description:  
 *--------------------------------------------------------------------------------------
 */
void debuglog(char *msg) 
{
    ofstream outf("debug_logg.txt", ios::app);
    if (!outf)
    {
        cerr << "Coudln't open logfile" << endl;
        return;
    }
#ifdef TIME
    time_t rawtime;
    time ( &rawtime );
    outf << "<-- |DEBUG| --> " << ctime (&rawtime);
    outf << "<-- |DEBUG| --> " << msg << endl;
#else
    outf << "<-- |DEBUG| --> " << msg << endl;
#endif
    outf.close();
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  Takes a string and a functionname as argument, write it out to a file
 * Description:  
 *--------------------------------------------------------------------------------------
 */
void debugloge(string msg, string function) 
{
    ofstream outf("debug_logg.txt", ios::app);
    if (!outf)
    {
        cerr << "Coudln't open logfile" << endl;
        return;
    }

#ifdef TIME
    time_t rawtime;
    time ( &rawtime );
    outf << "<-- |DEBUG| --> " << ctime (&rawtime);
    outf << "<-- |DEBUG| --> " << function << ": " << msg << endl;
#else
    outf << "<-- |DEBUG| --> " << function << ": " << msg << endl;
#endif
    outf.close();
}


