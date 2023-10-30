#include <iostream>
#include "FileManagement.h"   // Include the File Management Header
#include "Map.h"      // Include the Map header
#include "Sorting.h"  // Include the Sorting header
#include "Reduce.h"   // Include the Reduce header
#include <vector>

using std::string;
using std::cout;
using std::cerr;
using std::vector;
using std::endl;
using std::ostream;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " input_dir output_dir temp_dir" << endl;
        return 1;  // Exit with an error code
    }

    const string inputDir = argv[1];
    const string outputDir = argv[2];
    const string tempDir = argv[3];

    // Use the classes: FileManagement, Map, Sorting, and Reduce to implement your program logic
    FileManagement fileManager(inputDir, outputDir, tempDir);
    Map mapper(fileManager);
    Sorting sorter(fileManager);  // Use the Sorting class
    Reduce reducer(fileManager);  // Use the Reduce class

    // Define the folder name you want to process
    string targetFolderName = "shakespeare";  // Modify this to the desired folder name

    // List all files in the target folder
    vector<string> filesInFolder = fileManager.ListFilesInFolder(targetFolderName);

    // Use cerr for error messages to differentiate from regular program output
    if (filesInFolder.empty()) {
        cerr << "No files found in folder: " << targetFolderName << endl;
        return 1;  // Exit with an error code
    }

    // Iterate through all files in the folder and apply Map and Sorting phases
    for (const string& fileName : filesInFolder) {
        string filePath = targetFolderName + "/" + fileName;
        // Apply the Map phase to each file
        mapper.ProcessFile(filePath);
    }

    // Perform the Sorting phase
    sorter.SortIntermediateData(); // Implement the sorting logic

    // Perform the Reduce phase
    reducer.ProcessSortedData();  // Implement the reduced data processing

}