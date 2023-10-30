/*
* CSE687 Project 1
* Map Class Header file 
* Defines public methods map() and mapped_export()
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Map {
public:

	void map(string&); //Method takes in string of all input files and creates vertor of words 
	string mapped_export(); //Method uses locally defined vector of parsed words to create (key, value) pairs and store in mapped string 

private: 

	string filename; //String to store file name 
	string line; //String to store current line 
	vector <string> words; //Vector of tokenized words from input line
};
