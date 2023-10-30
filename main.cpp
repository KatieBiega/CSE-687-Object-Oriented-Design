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
	string mapped_string;
	string tempFilename = "TempFile.txt";
	string tempFileContent;
	string reduced_string;
	string outputFilename = "Final_OutputFile.txt";
	string successString = "";
	string successFilename = "SUCCESS.txt";

	//EXECUTIVE//
	//Prompt for input
	cout << "==== MAP & REDUCE ====\n\n";

	cout << "Enter the input directory: "; // this should contain the files for raw data input
	cin >> inputDirectory;
	cout << "Enter the output directory: "; // this should contain the final reduced files
	cin >> outputDirectory;
	cout << "Enter the temp directory: "; // this should contain the temp files between map and reduce
	cin >> tempDirectory;

	//WORKFLOW//
	//Create file management class based on the user inputs
	FileManagement FileManage(inputDirectory, outputDirectory, tempDirectory);
	fileString = FileManage.ReadAllFiles(); 

	Mapping.map(fileString);
	mapped_string = Mapping.string_export();
	FileManage.WriteToTempFile(tempFilename, mapped_string);
	tempFileContent = FileManage.ReadFromTempFile(tempFilename);
	Reduction.import(tempFileContent);
	Reduction.sort();
	Reduction.aggregate();
	reduced_string = Reduction.reduce_export();

	FileManage.WriteToOutputFile(outputFilename, reduced_string);
	FileManage.WriteToOutputFile(successFilename, successString);
}