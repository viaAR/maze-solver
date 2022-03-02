#ifndef A2_MAZE_MAZE_H
#define A2_MAZE_MAZE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Stack.h"

class Maze {
private:
    int m_ROW_SIZE = 0;
    int m_COL_SIZE = 0;
    std::string m_filename;

    std::vector<std::vector<char>> m_maze;
    std::vector<std::vector<char>> m_mazeSolution;

    std::pair<int, int> m_start {1, 0}, m_end {49, 50}, m_current = m_start;
    Stack m_mazeStack;

    std::vector<std::pair<int,int>> m_visitedSpaces {m_start};

public:
    Maze() = default;

    void buildMaze();
    void showMaze(std::vector<std::vector<char>>&) const;
    void displayExitPath();
    void outputSolution();

    int getRowSize() const;
    int getColSize() const;
    void setRowSize(int);
    void setColSize(int);
    void setFilename(std::string);
    void setStartingLocation(int,int);
    void setEndingLocation(int,int);

    void findExit();
    bool previouslyVisited(std::pair<int,int>);

    bool moveUp(int,int);
    bool moveDown(int,int);
    bool moveLeft(int,int);
    bool moveRight(int,int);
};

#endif