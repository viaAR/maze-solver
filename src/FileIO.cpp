#include "FileIO.h"

FileIO::~FileIO() {}

bool FileIO::validateFileType(std::string filename) {

    // Parse the string for the extension type
    return filename.substr(filename.find_last_of(".") + 1 ) == "txt";
}

bool FileIO::validateFileName(std::string filename) {

    return filename == "test.txt" || filename == "test2.txt" || filename == "test3.txt";
}

void FileIO::failedParse(std::string filename) {
    if (filename.empty()) {

        std::cout << "Missing file name." << std::endl;
        std::cout << "Format: <test.txt>" << std::endl;
    }
    else {

        std::cout << "Could not find the file you provided! You provided: " << filename << std::endl;
        std::cout << "Format: <test.txt> or <test2.txt> or <test3.txt>" << std::endl;
    }
}