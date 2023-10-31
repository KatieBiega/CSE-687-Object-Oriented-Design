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
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "Reduce.h"
using std::stringstream;

using std::vector;
using std::string;
using std::to_string;
using std::getline;
using std::cout;

void Reduce::import(string inputString) // breaks down text in string into multiple strings in the initial vector for use by reduce member functions
{
	stringstream stream(inputString); // intermediary placeholder between input line and vector 

	string inputLine = "";

	while (getline(stream, inputLine, '\n'))
	{
		//cout << "Adding importing strings to initial vector in Reduce class...\n";
		initialVector.push_back(inputLine);
	}

}

void Reduce::sort() {
	//cout << "Beginning sort in Reduce class...\n";
	std::sort(initialVector.begin(), initialVector.end()); // call sort function from standard C++ library to sort the strings in the vector alphabetically
	//cout << "Sort completed in Reduce class...\n";

}

void Reduce::aggregate() {

	string currentWord = ""; // the word currently being aggregated
	string currentAggregate = ""; // placeholder string; built before adding to new aggregatedVector
	string newWord = ""; // the word in the next key/value pair
	int begin;
	int end;
	int sw = 0;
	
	for (string currentLine : initialVector) // iterate through sorted vector to aggregate values into single strings to pass to the aggregatedVector
	{
		//cout << "Aggregating element" + currentLine + "\n";
		begin = currentLine.find_first_of("\""); // find the first quote in the key/value pair
		end = currentLine.find_last_of("\""); // find the second quote in the key/value pair
		newWord = currentLine.substr(begin + 1, end - begin - 1); // extract the string between these two delimiters
		//cout << "New word:" + newWord + "\n";


		if (newWord == currentWord && newWord != "") {

			currentAggregate = currentAggregate + ", 1";

		}
		else if (newWord != currentWord) {

			currentWord = newWord;

			if (currentWord == "") // do nothing if the current word is blank (should only apply at the very beginning of the loop)
			{ 
				
			}
			else{

				if (sw == 1) {
					currentAggregate = currentAggregate + "])";
					aggregatedVector.push_back(currentAggregate);
				}
				currentAggregate = "(\"" + newWord + "\"," + "[1";
				sw = 1;
			}
			
		}
		else {
			//cout << "ERROR: could not detect word" << "\n";
		}
	}

}

void Reduce::reduce() //iterate through the vector, getting the word and adding up each "1" that appears to find a total
{

	int begin;
	int end;

	size_t length;

	int total;

	string currentWord = ""; // key (word); function determines how many times this appears

	for (string Line : aggregatedVector)
	{
		//cout << "" + Line + "\n";
		string currentLine = Line;

		length = currentLine.length();
		total = 0;

		begin = currentLine.find_first_of("\"");
		end = currentLine.find_last_of("\"");
		string currentWord = currentLine.substr(begin + 1, end - begin - 1);


		for (int i = 0; i < length; i++) {

			

			if (currentLine[i] == '1') // add 1 to total if "1" is encountered when iterating through the string (this character should not appear otherwise)
			{
				total = total + 1;
			}
			else {
				//do nothing
			}

		}

		//cout << "Reduced word:" + currentWord + ", " + to_string(total) + "\n";
		reducedVector.push_back("(\"" + currentWord + "\"" + ", " + to_string(total) + ")"); // placed aggregated key/value combos into a new vector


	}
	//cout << "Vector reduction complete.\n";
}

string Reduce::reduce_export() {
	
	string outputString;
	int toggle = 0;

	for (string currentElement : reducedVector) // iterate through sorted vector to aggregate values into single strings to pass to the aggregatingVector
	{
		//cout << "Adding vector element to final Reduce output string..." + currentElement + "\n";

		if (toggle == 1) {
			outputString = outputString + "\n";
		}
		toggle = 1;
		outputString = outputString + currentElement;

		//cout << outputString + "\n";
	}

	return outputString;

}
