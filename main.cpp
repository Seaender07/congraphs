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
	//signal(SIGINT, scrclr);
	if(argc)
		parsarg(argc, argv);

	Screen screen;
	screen.loop();

	return 0;
}



//		  //
// TODO TODO TODO //
//		  //
// interrupt signal handling: signal(SIGNAL, function) REQUIRES <csignal>
// graph generation


//		     //
// FIXME FIXME FIXME //
//		     //
// free at the moment
