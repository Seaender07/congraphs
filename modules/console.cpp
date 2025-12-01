/*
 * CONSOLE.CPP
 * Implements Console class
 */

#include <iostream>
#include <cstdio>
#include "modules.h"

using namespace modules;	// Avoids namespace usage hassle (modules::)



//	  //
// PUBLIC //
//	  //

Console::Console(Screen &handle) : scrHandle(&handle)	// Constructor, references screen to access its public methods
{
}


int Console::readInput()	//	//	//	// Reads and parses console input
{
	currInput = "";		// Cleans out needed parameters (class members can access last status until now)
	parseInput = {};	//
	isGraph = false;	//

	std::cout << " $ ";
	std::getline(std::cin, currInput);		// Gets whole line to send for splitting
	utils::inputSplit(currInput, parseInput);	// Splits input and pushes each word to parseInput

	try
	{
		char cmdIndex = cmd.at(parseInput[0]);	// Retrieves matching commands for first keyword in parseInput (using .at() since cmd is const)
		scrHandle->printt({}, '#');		// Clears terminal only if a match is found (otherwise execution won't reach this point)
		switch(cmdIndex)			// Parses keywords TODO parameter parsing
		{
			case 'g':
				isGraph = true;
				break;
			case 'q':
				scrHandle->printt({"Quitting..."}, 's');
				return 0;					// Returns 0 if asked to quit (handled by Screen::loop())
				break;
		}
	}
	catch(std::out_of_range const&)			// Catches exception BY REFERENCE (by value throws a warning) when keyword is not matched
	{
		scrHandle->printt({"Key not found: '", parseInput[0], "'"}, 'e');	
		//return 0;
	}

	return (1 + isGraph);	// Returns 2 if graph is to be drawn, 1 otherwise
}


void Console::graph(Graph* graphptr)	//	//	// Makes graph (if generated) available to Screen
{
	// TODO graph creation should be triggered from here, but no inherent calculations should appear (leave that to modules::Graph)
}
