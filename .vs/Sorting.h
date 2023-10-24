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

using std::vector;
using std::string;

class Sorting {

	public:
		void fileRead(); // load file into vector

		void vectorSort();

		void vectorAggregate();

		void exportToFile();

	private:
		vector<string> sortingVector; // this contains all of the keys before and after sorting
		vector<string> aggregatingVector; // this is used to store aggregated keys
		string processName;

};