#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class fileManagement {
public:
    fileManagement(const string& inputDir, const string& outputDir, const string& tempDir)
        : inputDirectory(inputDir), outputDirectory(outputDir), tempDirectory(tempDir) {}

    // Read the contents of a file and return it as a string
    string ReadFile(const std::string& fileName) {
        ifstream file(inputDirectory + "/" + fileName);
        if (file.is_open()) {
            string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
            file.close();
            return content;
        }
        else {
            // Handle file not found or other errors
            cerr << "Error: Unable to read file " << fileName << endl;
            return "";
        }
    }

    // Write data to a temporary file
    void WriteToTempFile(const string& fileName, const string& data) {
        ofstream file(tempDirectory + "/" + fileName);
        if (file.is_open()) {
            file << data;
            file.close();
        }
        else {
            // Handle error
            cerr << "Error: Unable to write to temporary file " << fileName << endl;
        }
    }

    // Move a temporary file to the output directory
    void MoveToOutput(const string& tempFileName, const string& outputFileName) {
        // Implement file move operation (e.g., using std::filesystem)
    }

    // Other file management operations can be added as needed

private:
    string inputDirectory;
    string outputDirectory;
    string tempDirectory;
};

int main(int argc, char** argv) {
    
    
    if (argc != 4) {
        std::cerr << "Usage: program input_directory output_directory temp_directory" << endl;
        return 1;
    }

    fileManagement fileManager(argv[1], argv[2], argv[3]);

    // Example usage:
    string content = fileManager.ReadFile("input.txt");
    fileManager.WriteToTempFile("temp.txt", content);
    fileManager.MoveToOutput("temp.txt", "output.txt");

    return 0;
}
