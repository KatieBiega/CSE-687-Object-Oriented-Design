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

	void import(string inputString); // import the string and place it into the initialVector
	void sort(); // sort the strings into alphabeetical order (ignore this, unless std::map's automatic sorting is insufficient)
	void aggregate(); // aggregate each key/value pair with the same key into single keys with many attached values
	void reduce(); // reduce the aggregated values into a single total value for the associated key
	string export(); // export the final educed vector as a single string

private:

	vector<string> initialVector; // keys pulled from source file in their original state
	vector<string> aggregatedVector; // this is used to store aggregated keys
	vector<string> reducedVector; // conversion of the reducedVector into a reduced version

};
