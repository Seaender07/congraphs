/*
 * SCREEN.CPP
 * Implements Screen class
 */

#include <iostream>
#include <cstdio>
#include "modules.h"


// FRAME PATTERNS
const Ptn straight = { '*', '|', '-' };



//	     //
// PROTECTED //
//	     //

void Screen::reschg(int &w, int &h)	// Resizes screen matrix to (w,h)
{
	matrix.resize(w);
	for(int i = 0; i < w; i++)
		matrix[i].resize(h);

	curres[0] = w;			// Assigns current resolution to curres[]
	curres[1] = h;			//
}


void Screen::ptnpsh(const Ptn &ptn)	// Pushes screen pattern to screen matrix TODO implement rich frame patterns
{

	// PUSH VERTICES
	matrix[0][0] = ptn.vertex;
	matrix[curres[0]-1][0] = ptn.vertex;
	matrix[0][curres[1]-1] = ptn.vertex;
	matrix[curres[0]-1][curres[1]-1] = ptn.vertex;
		// input bar region
	matrix[0][curres[1]-3] = ptn.vertex;
	matrix[curres[0]-1][curres[1]-3] = ptn.vertex;

	// PUSH SIDES
	for(int y = 1; y < (curres[1]-1); y++)
	{
		if(y != (curres[1]-3))				// Avoids overriding console region vertices
		{
			matrix[0][y] = ptn.side;
			matrix[curres[0]-1][y] = ptn.side;
		}
	}


	// PUSH BASES
	for(int x = 1; x < (curres[0]-1); x++)
	{
		matrix[x][0] = ptn.base;
		matrix[x][curres[1]-1] = ptn.base;
		matrix[x][curres[1]-3] = ptn.base;		// Console region separator
	}
}


void Screen::scrdrw()	//	//	// Draws screen from pushed matrix
{
	if(!hasInit)						// clear screen only on initialization
	{
		scrclr();
		hasInit = true;
	}
	//matrix[0][0] = '0';
	//matrix[0][1] = '1';
	//matrix[0][2] = '2';
	//matrix[1][0] = '1';
	//matrix[2][0] = '2';
	
	// DRAW PUSHED MATRIX
	for(int y = 0; y < curres[1]; y++)
	{
		for(int x = 0; x < curres[0]; x++)
		{
			scrpos(x, y);
			std::cout << matrix[x][y];
			if(matrix[x][y] == '\0') printf(" ");
		}
	}

}


void Screen::lnedrw(int line)	//	// Draws single line from pushed matrix (efficient for small updates)
{
	for(int x = 0; x < curres[0]; x++)
	{
		scrpos(x, line);
		std::cout << matrix[x][line];
	}
}



//	  //
// PUBLIC //
//	  //

Screen::Screen()	//	//	//	//	//	//	// Adaptive resolution constructor, to use as default
{
	int* res = getscreen(); 
	reschg(res[0], res[1]);
	delete res;		// res is not needed anymore, frees up some memory

	printf("\nres:\t%i; %i\n", res[0], res[1]);
	printf("\ncurres:\t%i; %i\n", curres[0], curres[1]);
	printf("\nmatrix:\t%i; %i\n", (int)matrix.size(), (int)matrix[1].size());

	ptnpsh(straight);
}


Screen::Screen(int &w, int &h)	//	//	//	//	//	// Static resolution constructor, use only on specific need
{
	reschg(w, h);
	ptnpsh(straight);
}


Screen::~Screen()	//	//	//	//	//	//	// Destructor, clears screen
{
	scrclr();
	//printf("destructor called\n");
}


int* Screen::getres()	//	//	//	//	//	//	// Only public method to access resolution data
{
	return curres;
}


void Screen::loop()	//	//	//	//	//	//	// Handles screen behavior
{
	int exitCode;				// Will store exit code

	do
	{
		scrdrw();			// Clear screen TODO improve efficiency, lnedrw() + exitCode to determine graph or nah??
		scrpos(1, curres[1]-2);		// Prepares cursor for console input
		exitCode = console.readInput();	// Lets console accept input
		console.graph(graphHandle);	// Attach graph (if produced) to pointer handle for drawing
	} while(exitCode != 0);			// Execute until console signals 'quit' (exitCode = 0)
}


void Screen::printt(std::vector<std::string> message, char level)	// Prints to terminal (accessible through a class pointer)
{
	lnedrw((curres[1]-4));		// Clears out terminal line
	scrpos(1, (curres[1]-4));	// Sets position to terminal line

	std::string color;		// Stores color code
	switch(level)			// Matches color code
	{
		case 'i':
			color = TCYAN;
			break;
		case 's':
			color = TGREEN;
			break;
		case 'w':
			color = TAMBER;
			break;
		case 'e':
			color = TRED;
			break;
		default:
			color = TDEFLT;
			break;
	}

	std::cout << " > " << color;			// Iterate through message elements and print each element (HAS TO BE std::string)
	for(int i = 0; i < (int)(message.size()); i++)	//
	{						//
		std::cout << message[i];		//
	}						//
	std::cout << TDEFLT;				//
}



//	 //
// OTHER //
//	 //
