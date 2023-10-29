#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include "Map.h"

using std::string;
using std::ifstream;

typedef std::map<std::string, int> StrIntMap;

void map::map(const string& filename, string& line)
{
	//read in all the words
	StrIntMap word_count;
	
	while (filename >> line)
	{
		//remove punctuation
		while ((int index = line.find_first_of(".,:!?\\;-*+[]<>() '")) != string::npos)
		{
			line.erase(index, 1);
		}
		//set to lowercase 
		std::transform(line.begin(), line.end(), line.begin(),
			[](unsigned char c) { return std::tolower(c); });
		//increase map word count
		++word_count[word];
	}
}

void map::export(map word_count)
{
	for (word_count::iterator p = word_count.begin(); p != word_count.end(); ++p) {
		std::cout << "(\"" << p->first << "\"," << p->second << ")\n";
	}
	//write to file

}