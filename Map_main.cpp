/*
* Test main file for testing Map Class 
* Including Map header file
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

using namespace std;

int main() {

	//Opening test file in directory
	string filename = "Cymbeline";
	ifstream in("Cymbeline.txt");
	if (!in.is_open())
	{
		cout << "failed to open file\n";
	}

	//Creating Map CLass object variables for passing text 
	Map obj;
	string line;

	//Command structure for calling Map class methods 
	while (getline(in, line))
	{
		obj.map(filename, line);
	}
	obj.file_export(filename);

	//Close file stream	
	in.close();
}
