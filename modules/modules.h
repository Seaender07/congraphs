/*
 * MODULES.H
 * Collects all module declarations
 */

#include <iostream>
#include <cstdio>
#include <vector>



// PLATFORM-SPECIFIC FUNCTIONS (unix.cpp)
int* getscreen();
void scrclr();
void scrpos(int x, int y);

// FORWARD DECLARATIONS
class Screen;



//	//
// DATA //
//	//

struct Ptn
{
	char vertex, side, base;
	char** richvertex, richside, richbase;
};



//	   //
// CLASSES // (See specific implementation files for method usage)
//	   //

namespace modules	// HIDES CLASSES FROM USER
{
	class Graph	// Graph handling TODO
	{
		private:

		public:

	};

	class Console	// Console handling
	{
		private:
			std::string currInput;	// Stores current input string TODO change to array std::string*?
			Screen* scrHandle;	// Points to screen, assigned on construction
		public:
			Console(Screen &handle);
			int readInput();
			void graph(modules::Graph* graphptr);
	};
}

class Screen	//	// Screen handling
{
	protected:
		void reschg(int &w, int &h);
		void ptnpsh(const Ptn &ptn);
		void scrdrw();
		void lnedrw(int line);

		bool hasInit = false;			// Changes to true after frame pattern is first drawn
		int curres[2] = {0, 0};			// Stores current screen resolution: {x, y} => {w, h} => {cols, rows}
		std::vector<std::vector<char>> matrix;	// Screen matrix, virtual representation of screen

		modules::Console console = modules::Console(*this);		// Creates a modules::Console object for in-'loop()' usage
		modules::Graph* graphHandle;					// Creates a modules::Graph* object pointer for graph referencing


	public:
		Screen();
		Screen(int &w, int &h);
		~Screen();

		int* getres();
		void loop();
};
