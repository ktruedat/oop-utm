#include <iostream>
#include <string>
#include <ctime>

class File {
private:
    std::string filePath;
    std::string filename;
    std::string fileExtension;
    std::size_t fileSize;
    time_t creationTime;

public:
    File(const std::string& filePath, const std::string& extension, std::size_t size) {
        this->filePath = filePath;
        this->filename = filePath.substr(filePath.find_last_of('/') + 1);
        this->fileExtension = extension;
        this->fileSize = size;
        this->creationTime = std::time(0);
    }

    File(const std::string& filename) {
        this->filename = filename;
        this->fileExtension = "";
        this->fileSize = 0;
        this->creationTime = std::time(0);
    }

    void renameFile(const std::string& newFilename) {
        filename = newFilename;
    }

   void transferToDirectory(const std::string& newDirectory) {
        std::string newFilePath = newDirectory + filename;
        std::cout << "Transfer " << filename << " to directory " << newDirectory << std::endl;
        filePath = newFilePath;
    }

    void changeFileExtension(const std::string& newExtension) {
        fileExtension = newExtension;
    }

     void displayFileInfo() {
        std::cout << "Drumul fișierului: " << filePath << std::endl;
        std::cout << "Numele fișierului: " << filename << std::endl;
        std::cout << "Extensia: " << fileExtension << std::endl;
        std::cout << "Mărimea: " << fileSize << " bytes" << std::endl;
        std::cout << "Data și ora creării: " << std::ctime(&creationTime) << std::endl;
    }
};

int main() {
    File myFile("document.txt", "doc", 1024);
    myFile.displayFileInfo();

    myFile.renameFile("new_document.txt");
    myFile.displayFileInfo();

    std::string abc = "pdf";
    std::string& extension = abc;
    myFile = extension;

    myFile.transferToDirectory("/new/directory/");
    myFile.displayFileInfo();

    myFile.changeFileExtension("pdf");
    myFile.displayFileInfo();

    return 0;
}
