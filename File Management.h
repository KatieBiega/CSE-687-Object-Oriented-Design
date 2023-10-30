#ifndef FILE_MANAGEMENT
#define FILE_MANAGEMENT

#include <string>

class FileManagement {
public:
    FileManagement(const std::string& inputDir, const std::string& outputDir, const std::string& tempDir);

    std::string ReadFile(const std::string& fileName);
    std::string ReadAllFiles();
    void WriteToTempFile(const std::string& fileName, const std::string& data);
    void MoveToOutput(const std::string& tempFileName, const std::string& outputFileName);

    std::ifstream OpenFileForRead(const std::string& fileName);
    std::ofstream OpenFileForWrite(const std::string& fileName);

private:
    std::string inputDirectory;
    std::string outputDirectory;
    std::string tempDirectory;
};

#endif

