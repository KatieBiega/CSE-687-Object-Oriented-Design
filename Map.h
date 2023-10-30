/*
* CSE687 Project 1
* Map Class Header file 
* Defines public methods map() and file_export()
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Map {
public:

	void map(string&); //Method takes in current handeling input file name and parsed file line, and then creates vertor of words. 
	string string_export(); //Method takes in current handeling file name, and local vector of parsed words to write (key, value) pairs to file. 

private: 

	string filename; //String to store file name 
	string line; //String to store current line 
	vector <string> words; //Vector of tokenized words from input line
};
