#include "File Management.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::stringstream;

FileManagement::FileManagement(const std::string& inputDir, const std::string& outputDir, const std::string& tempDir)
    : inputDirectory(inputDir), outputDirectory(outputDir), tempDirectory(tempDir) {}

// function to read files from provided directory
string FileManagement::ReadAllFiles() { 

    string content; // content of directory 
    string fullContent; // full content of directory 
    string temp; //temp file string
    ifstream fileStream; // opens and reads data from file
    string inputLine; // take input
    
// functtion to iterate directory files content into a string
    for (auto& file : std::filesystem::directory_iterator(inputDirectory)){

        fileStream.open(file.path().string());

        while (getline(fileStream, inputLine))
        {
            content = content + inputLine;
        }
 
        fullContent = fullContent + content;
    
    }
    return fullContent; // returns directory and saves to string
    fileStream.close();
}
//reads the directory from the temp file 
string FileManagement::ReadFromTempFile(const std::string& fileName) {
    ifstream file(tempDirectory + "/" + fileName);
    if (file.is_open()) {
        std::string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();
        return content;
    }
    else {
        // Handle file not found or other errors
        cerr << "Error: Unable to read temp file " << fileName << endl;
        return "";
    }
}
// takes directory and creates a temp file 
void FileManagement::WriteToTempFile(const string& fileName, const string& data) {
    ofstream file(tempDirectory + "/" + fileName);
    if (file.is_open()) { 
        file << data;
        file.close(); 
    }
    else {
        
        cerr << "Error: Unable to write to temporary file " << fileName << endl; // error if unable to write to temp file
    }
}
//writes data to file in an output directory
void FileManagement::WriteToOutputFile(const string& fileName, const string& data) {
    ofstream file(outputDirectory + "/" + fileName);
    if (file.is_open()) {
        file << data;
        file.close();
    }
    else {

        cerr << "Error: Unable to write to file " << fileName << endl; // error display if unable to write to temp file 
    }
}

