#ifndef DEBUG_H
#define DEGUG_H

#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>
#include <iomanip>
#include "utilities.h"


using namespace std;
/*
 * =====================================================================================
 *        Class:  §
 * 
 *  Description:  Debug methods
 * 
 *       Author:  Joakim Bech
 *      Created:  2004-05-31 13.23.16 CEST
 *     Revision:  none
 * =====================================================================================
 */

#ifndef NDEBUG
#   define DPRINT(expr)         (std::clog << "<-- |DEBUG| --> " << #expr << ": " << expr << std::endl)
#   define DPRINTF(expr, func)  (std::clog << "<-- |DEBUG| --> " << func << ": " << #expr \
												<< ": " << expr << std::endl)
#   define DPRINTE(expr)        (std::clog << "<-- |DEBUG| --> " << #expr << ": " << expr \
                                    << setw(10) << "( " << __FILE__ << ":" << __LINE__ << " )" << std::endl)
#else
#	define DPRINT(expr) 				(use(&expr))
#	define DPRINTF(expr, func)		(use(&expr))
#	define DPRINTE(expr)       	(use(&expr))
#endif

void debuglog(int msg);
void debuglog(string msg);
void debuglog(char *msg);
void debugloge(string msg, string function);

#endif
