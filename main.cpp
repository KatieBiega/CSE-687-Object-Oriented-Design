#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "Reduce.h"
#include "Map.h"
#include "File Management.h"


using std::stringstream;
using std::vector;
using std::string;
using std::to_string;
using std::getline;
using std::cout;
using std::cin;



int main() {
	string fileName = "";
	string fileString = "";
	string inputDirectory = "";
	string outputDirectory = "";
	string tempDirectory = "";

	Reduce Reduction;
	Map Mapping;


	//Prompt for input
	cout << "==== MAP & REDUCE ====\n\n";

	cout << "Enter the input directory: "; // this should contain the files for raw data input
	cin >> inputDirectory;
	cout << "Enter the output directory: "; // this should contain the final reduced files
	cin >> outputDirectory;
	cout << "Enter the temp directory: "; // this should contain the temp files between map and reduce
	cin >> tempDirectory;

	//create file management class based on the user inputs
	FileManagement FileManage(inputDirectory, outputDirectory, tempDirectory);

	fileString = FileManage.ReadFile(fileName); 
	

}