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
using std::vector;
using std::stringstream;

FileManagement::FileManagement(const std::string& inputDir, const std::string& outputDir, const std::string& tempDir)
    : inputDirectory(inputDir), outputDirectory(outputDir), tempDirectory(tempDir) {}


string FileManagement::ReadAllFiles() {

    string content;
    string fullContent;

    for (auto& file : std::filesystem::directory_iterator(std::filesystem::current_path())){

        while (file >> content) {
            fullContent = fullContent + content;
        }
    }
    return fullContent;
}

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

void FileManagement::WriteToTempFile(const string& fileName, const string& data) {
    ofstream file(tempDirectory + "/" + fileName);
    if (file.is_open()) {
        file << data;
        file.close();
    }
    else {
        
        cerr << "Error: Unable to write to temporary file " << fileName << endl;
    }
}

void FileManagement::WriteToOutputFile(const string& fileName, const string& data) {
    ofstream file(outputDirectory + "/" + fileName);
    if (file.is_open()) {
        file << data;
        file.close();
    }
    else {

        cerr << "Error: Unable to write to temporary file " << fileName << endl;
    }
}

