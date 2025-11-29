/*
 * UNIX.CPP
 * Platform-specific implementations for Unix/Linux systems
 */

#ifdef __linux__



#include <iostream>
#include <cstdio>
#include <sys/ioctl.h>
#include <unistd.h>
#include "modules.h"



int* getscreen()//	//	// Get console size
{
	
	struct winsize w;					// I just trust this couple of lines
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);			//

	return new int[2] {(int)w.ws_col, (int)w.ws_row};	// Returns int[2] array with screen dimensions
}

void scrclr()	//	//	// Clears (flushes) screen and places cursor at (1, 1)
{
	std::cout << "\033[2J\033[1;1H";
}

void scrpos(int x, int y)	// Moves cursor at (x, y)
{
	x++; y++;						// Translate origin for ANSI escape (0,0) => (1,1)
	std::cout << "\033[" << y << ";" << x << "H";
}



#endif
