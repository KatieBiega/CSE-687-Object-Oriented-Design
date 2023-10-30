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

string FileManagement::ReadFile(const std::string& fileName) {
    ifstream file(inputDirectory + "/" + fileName);
    if (file.is_open()) {
        std::string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();
        return content;
    }
    else {
        // Handle file not found or other errors
        cerr << "Error: Unable to read file " << fileName << endl;
        return "";
    }
}

string FileManagement::ReadAllFiles() {

    string content;
    string fullContent;
    ifstream istream;
    stringstream sstream;

    for (auto& file : std::filesystem::directory_iterator(std::filesystem::current_path())){

        file.open();
        content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        fullContent = fullContent + content;

    }
    return content;
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

void FileManagement::MoveToOutput(const string& tempFileName, const string& outputFileName) {
    // Implement file move operation (e.g., using std::filesystem)
}

std::ifstream FileManagement::OpenFileForRead(const std::string& fileName) {
    std::ifstream file(inputDirectory + "/" + fileName);
    return file;
}

std::ofstream FileManagement::OpenFileForWrite(const std::string& fileName) {
    std::ofstream file(tempDirectory + "/" + fileName);
    return file;
}
