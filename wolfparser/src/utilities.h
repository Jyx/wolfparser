#ifndef UTILITIES_H
#define UTILITIES_H
/*
 * =====================================================================================
 *        Class:  
 * 
 *  Description:  Method for...
 * 
 *       Author:  Joakim Bech
 *      Created:  2004-05-31 13.27.08 CEST
 *     Revision:  none
 * =====================================================================================
 */

#ifdef WIN32
#include "../stdafx.h"
#endif

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/* Dummy to disable warning about unused variabled */
void use(const void*);

string to_lower(string);

#endif

