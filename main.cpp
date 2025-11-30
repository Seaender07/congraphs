/*
 * MAIN.CPP
 * Pretty self-explanatory
 */

#include <iostream>
#include <cstdio>
#include <csignal>
#include "main.h"
#include "modules/modules.h"



int main(int argc, char** argv)
{
	if(argc)
		parsarg(argc, argv);

	Screen screen;
	screen.loop();

	return 0;
}



//		  //
// TODO TODO TODO //
//		  //
// MAIN.H	| command line arguments parsing
// UNIX.CPP	| interrupt signal handling: signal(SIGNAL, function) REQUIRES <csignal>
// GRAPH.CPP	| graph generation
// CONSOLE.CPP	| console argument parsing
// CONSOLE.CPP	| trigger graphic creation from Console::graph(Graph* graphptr), return reference to graph but include NO calculations


//		     //
// FIXME FIXME FIXME //
//		     //
// UTILS | 'using namespace utils' causes linker undefined reference
