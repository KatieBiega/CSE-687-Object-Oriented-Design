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
using std::getline;
using std::ifstream;
using std::ofstream;

void Reduce::fileRead() // pulls text from file and stores each line as a string in a vector for use by reduce function
{

}

void Reduce::reduce() //iterate through the vector, calculating how many items each key with the same name appears
{
	int maxIterator = 1;

	string key = ""; // key (word); function determines how many times this appears

	for (int i = 0; i < maxIterator; i++) 
	{

	}

}

void Reduce::export() 
{

	
}