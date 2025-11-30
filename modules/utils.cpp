/*
 * UTILS.CPP
 * Implementation of various utilities
 */

#include <iostream>
#include <cstdio>
#include <regex>
#include "modules.h"

//using namespace utils;	// Avoids namespace usage hassle (utils::) FIXME using this causes linker undefined reference



void utils::inputSplit(std::string input, std::vector<std::string> &split)	// Splits out a given string down into its words (separated by re)
{
	// NOT MY CODE | credits: inspired by @darune on StackOverflow
	std::regex re("[ *]");								// Splits only based on spaces
	std::sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;	// @darune: "The '-1' is what makes the regex split (-1 := what was not matched)"
	split = std::vector<std::string>{first, last};
}
