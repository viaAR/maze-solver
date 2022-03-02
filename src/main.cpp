#include "Maze.h"
#include "FileIO.h"

using namespace std;

int main(int argc, char** argv) {

    FileIO file;
    std::string testFile;

    if (argc > 1) {

        testFile = argv[1];

        if (file.validateFileType(testFile) && file.validateFileName(testFile)) {
            Maze maze;

            // Specify the dimensions of the maze and the name of the file
            maze.setRowSize(51);
            maze.setColSize(51);
            maze.setFilename(testFile);

            // Specify the m_start and m_end of the maze
            maze.setStartingLocation(1, 0);
            maze.setEndingLocation(49, 50);

            // Construct the maze in memory
            maze.buildMaze();

            // Search the maze for an exit
            maze.findExit();
        }
        else {

            file.failedParse(testFile);
        }
    }
    else {

        file.failedParse(testFile);
    }

    return 0;
}
