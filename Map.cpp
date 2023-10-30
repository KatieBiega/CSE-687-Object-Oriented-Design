/*
* CSE687 Project 1
*
* The map class will contain a public method map(), that accepts a key and value. 
* The key will be the file name and the value will be a single line of raw data from the file. 
* The map() function will tokenize the value into distinct words (remove punctuation, whitespace and capitalization). 
* The map() function will call a second function export() that takes a key and value as two parameters. 
* The export function will buffer output in memory and periodically write the data out to disk (periodicity can be based on the size of the buffer). 
* The intermediate data will be written to the temporary directory (specified via command line). 
* 
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include "Map.h"

using namespace std;

void Map::map(const string&, string& line)
{

	//Initializing temporary string for buffering words
	string temp = "";
	
	//Remove all punctuation and special characters excpet spaces from input line
	int index;
	while ((index = line.find_first_of(".,-:!?\\;*+[]<>()'")) != string::npos)
	{
		line.erase(index, 1);
	}

	//Set all alphabetic characters in input line to lower case 
	transform(line.begin(), line.end(), line.begin(),
		[](unsigned char c) { return tolower(c); });

	//streaming input line string delimtted by spaces for tokenization
	stringstream ss(line);

	//Iterating through string stream to create and store vector of words 
	while (ss >> temp)
	{
		words.push_back(temp);
	}

}

void Map::file_export(const string& filename)
{
	//Creating intermediate file to store Mapped results
	ofstream tempfile;
	string TempFilename = "Mapped_" + filename + ".txt";
	tempfile.open(TempFilename);

	//All words stored in vector from input file are written into the intermediate file as (key, value) pair 
	for (int i = 0; i < words.size(); i++)
	{
		tempfile << "(" + words[i] + ", 1)\n";
	}

	//Closing intermediate file stream
	tempfile.close();
}
