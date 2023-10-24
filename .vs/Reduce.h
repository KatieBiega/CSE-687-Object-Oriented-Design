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
#include <string>
#include <vector>

using std::vector;
using std::string;

class Reduce {
public:

	void fileRead();
	void reduce();
	void export();

private:

	int iterator = 0;
	vector<string> initialVector; // keys pulled from source file in their original state
	vector<string> reducedVector; // conversion of the reducedVector into a reduced version
	string processName;
};
