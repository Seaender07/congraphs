/*
 * MAIN.H
 * Collects main.cpp related utilities
 */

#include <iostream>
#include <cstdio>
#include <unistd.h>



//		//
// DECLARATIONS //
//		//

bool parsarg(int &carg, char** &varg);



//	       //
// DEFINITIONS //
//	       //

bool parsarg(int &carg, char** &varg)	// Parses command line arguments TODO parsing
{
	return (carg > 0 ? true : false);
}
