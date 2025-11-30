/*
 * MODULES.H
 * Collects all module declarations
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>



// PLATFORM-SPECIFIC FUNCTIONS (unix.cpp)
int* getscreen();
void scrclr();
void scrpos(int x, int y);

// UTILITIES
namespace utils
{
	void inputSplit(std::string input, std::vector<std::string> &split);
}


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
			const std::map<std::string, char> cmd = {	// List of console commands mapped to a single char
				{ "graph", 'g' },
				{ "quit", 'q' }
			};
			std::string currInput;				// Stores current input string as a whole
			std::vector<std::string> parseInput;		// Stores current input as splitted words
			bool isGraph = false;				// Communicates to screen (through return of readInput()) whether a graph is to be drawn
			Screen* scrHandle;				// Points to screen, assigned on construction
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
