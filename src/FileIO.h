#ifndef ASSIGNMENT_2_FILEIO_H
#define ASSIGNMENT_2_FILEIO_H

#include <iostream>
#include <string>

class FileIO {
public:
    FileIO(){};
    ~FileIO();

    bool validateFileType(std::string);
    bool validateFileName(std::string);
    void failedParse(std::string);
};


#endif