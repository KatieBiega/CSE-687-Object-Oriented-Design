/*
CSE 687 Object Oriented Design

Reduce Class: The reduce class will have a method reduce() that will take a string
with one key and an iterator of integers. The reduce function should sum all the
values in the iterator and then call an export function (different from the Map class).
The export function will take two parameters, the key and resulting reduced value,
and write the result out to the output directory. Upon success an additional empty file
SUCCESS will be written out to the output directory. The reduce method itself should
not directly deal with any File IO.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Reduce.h"
using std::ifstream;

using std::vector;
using std::string;
using std::to_string;
using std::getline;
using std::ifstream;
using std::ofstream;

void Reduce::fileRead() // pulls text from file and stores each line as a string in a vector for use by reduce function
{
	ifstream file;

	file.open("sortingOutput.txt");

	string inputLine = ""; // intermediary placeholder between file line and vector 

	while (getline(file, inputLine, '\n'))
	{
		initialVector.push_back(inputLine);
	}

	file.close();
}

void Reduce::reduce() //iterate through the vector, getting the word and adding up each "1" that appears to find a total
{

	string currentKey = ""; // key (word); function determines how many times this appears

	for (string Line : initialVector)
	{
		string currentLine = Line;

		int length = currentLine.length();
		int total = 0;


		for (int i = 0; i < length; i++) {

			

			if (currentLine[i] = 1) // add 1 to total if "1" is encountered when iterating through the string (this character should not appear otherwise)
			{
				total++;
			}
			else if () {

			}
			else {

			}

		}

		reducedVector.push_back("(\"" + currentKey + "\"" + ", [" + to_string(total) + "]");

	}

}

void Reduce::export() 
{
	ofstream reducedVector("./reduceOutput.txt");
	
}