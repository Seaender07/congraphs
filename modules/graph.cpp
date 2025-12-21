/*
 * GRAPH.CPP
 * Implements Graph class
 */

#include <iostream>
#include <cstdio>
#include "modules.h"

using namespace modules;	// Avoids namespace usage hassle (modules::)



//	  //
// PUBLIC //
//	  //

Graph::Graph(std::string strequation) : strEq(strequation)	// Constructor, also does spell check
{
	//{4bits empty}[=][x][y][]
	log = 0xf1;
	for(unsigned int i = 0; i < strEq.size(); i++)
	{
		(strEq[i] == '=' ? (log ^= 0x08) : 0);
		(strEq[i] == 'x' ? (log ^= 0x04) : 0);
		(strEq[i] == 'y' ? (log ^= 0x02) : 0);
	}
}


unsigned char Graph::getlog()
{
	return log;
}
