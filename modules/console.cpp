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
	std::cout << " > ";
	std::cin >> currInput;
	// TODO bool isGraph (add this to return value (1 since no exit), so that screen knows if to begin graph)
	return (currInput == "quit" ? 0 : 1);	// Returns 0 if asked to quit (handled by Screen::loop())
}

void Console::graph(Graph* graphptr)	//	//	// Makes graph (if generated) available to Screen
{
	// TODO graph creation should be triggered from here, but no inherent calculations should appear (leave that to modules::Graph)
}
