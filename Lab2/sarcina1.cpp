#include <iostream>
#include <string>
#include <ctime>

class File {
private:
    std::string filename;
    std::string fileExtension;
    std::size_t fileSize;
    time_t creationTime;

public:
    File(const std::string& filename, const std::string& extension, std::size_t size) {
        this->filename = filename;
        this->fileExtension = extension;
        this->fileSize = size;
        this->creationTime = std::time(0);
    }

    // Constructor de schimbare a tipului (parametrul - numele de fișier)
    File(const std::string& filename) {
        this->filename = filename;
        // Presupunem aici că extensia și celelalte atribute sunt necunoscute la momentul creării obiectului.
        this->fileExtension = "";
        this->fileSize = 0;
        this->creationTime = std::time(0);
    }

    // Funcția pentru redenumirea fișierului
    void renameFile(const std::string& newFilename) {
        filename = newFilename;
    }

    // Funcția pentru transfer în alt director
    void transferToDirectory(const std::string& newDirectory) {
        // Implementați aici logica de transfer în noul director.
        std::cout << "Transfer " << filename << " to directory " << newDirectory << std::endl;
    }

    // Funcția pentru modificarea anexei de asociere
    void changeFileExtension(const std::string& newExtension) {
        fileExtension = newExtension;
    }

    // Funcție pentru a afișa informațiile despre fișier
    void displayFileInfo() {
        std::cout << "Numele fișierului: " << filename << std::endl;
        std::cout << "Extensia: " << fileExtension << std::endl;
        std::cout << "Mărimea: " << fileSize << " bytes" << std::endl;
        std::cout << "Data și ora creării: " << std::ctime(&creationTime) << std::endl;
    }
};

int main() {
    // Exemplu de utilizare a clasei File
    File myFile("document.txt", "doc", 1024);
    myFile.displayFileInfo();

    // Redenumirea fișierului
    myFile.renameFile("new_document.txt");
    myFile.displayFileInfo();

    // Transferul în alt director
    myFile.transferToDirectory("/new/directory/");
    myFile.displayFileInfo();

    // Modificarea anexei de asociere
    myFile.changeFileExtension("pdf");
    myFile.displayFileInfo();

    return 0;
}
