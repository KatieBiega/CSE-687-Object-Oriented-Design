/*
CSE 687 Object Oriented Design

Sorting: The intermediary results will need to be sorted and aggregated. The
intermediate file will contain output such as: (“a”, 1), (“the”, 1), (“is”, 1), (“the”, 1), (“a”, 1). 

The reducer requires the same data in the format:
(“a”, [1, 1, …]), (“the”, [1, 1, …]), (“is”, [1, …]), …
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "Sorting.h"

using std::vector;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

void Sorting::fileRead() //read file contents and store in a vector for use in the sorting algorithm
{
	ifstream file;

	file.open("sortingInput.txt");

	string inputLine = ""; // intermediary placeholder between file line and vector 

	while(getline(file, inputLine, '\n'))
	{
		sortingVector.push_back(inputLine);
	}
	
	file.close();
}

void Sorting::vectorSort() {

	std::sort(sortingVector.begin(), sortingVector.end()); // call sort function from standard C++ library to sort the strings in the vector alphabetically

}

void Sorting::vectorAggregate() {

	//std::sort(aggregatingVector.begin(), sortingVector.end()); // iterate through sorted vector

}

void Sorting::exportToFile() //export the aggregated vector as a text file
{

	ofstream sortedVector("./sortingOutput.txt");

}