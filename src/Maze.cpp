#include "Maze.h"

// Create the maze from the txt file
void Maze::buildMaze() {

    std::ifstream ifs {"../tests/" + m_filename};
    std::string line;

    if (!ifs.is_open()) {

        std::cout << "Could not open m_maze." << std::endl;
    }
    else {

        for (int i = 0; i < m_ROW_SIZE; i++) {

            // Temp vector to push in values
            std::vector<char> row;

            // Read each line from the txt file as a row
            getline(ifs, line);

            for (int j = 0; j < m_COL_SIZE; j++) {

                // Pick out the characters in each line and insert them to the row
                row.push_back(line[j]);
            }

            // Push each row into m_maze
            m_maze.push_back(row);
        }

        ifs.close();
    }
}

// Write the maze to the console
void Maze::showMaze(std::vector<std::vector<char>>& maze) const {

    for (int i = 0; i < getRowSize(); i++) {

        for (int j = 0; j < getColSize(); j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}

// Show the user the path taken to the exit
void Maze::displayExitPath() {

    auto mapCopy = m_maze;
    auto stackCopy = m_mazeStack;

    while (!stackCopy.isEmpty()) {

        mapCopy[stackCopy.peek().first][stackCopy.peek().second] = '#';
        stackCopy.pop();
    }

    // Show the user the solution in the console
    showMaze(mapCopy);

    // Save the solution for writing to an output file
    m_mazeSolution = mapCopy;
    outputSolution();
}

// Write the solution to a file
void Maze::outputSolution() {

    std::string outputFile {"../solved/solution_" + m_filename};
    std::ofstream ofs {outputFile};

    if (ofs.is_open()) {

        for (int i = 0; i < getRowSize(); i++) {

            std::string line;

            for (int j = 0; j < getColSize(); j++) {

                line += m_mazeSolution[i][j];
            }

            line += '\n';
            ofs << line;
        }
    }

    ofs.close();
}

int Maze::getRowSize() const {
    return m_ROW_SIZE;
}

int Maze::getColSize() const {
    return m_COL_SIZE;
}

void Maze::setRowSize(int rows) {
    m_ROW_SIZE = rows;
}

void Maze::setColSize(int cols) {
    m_COL_SIZE = cols;
}

void Maze::setFilename(std::string txtFileName) {
    m_filename = txtFileName;
}

void Maze::setStartingLocation(int x, int y) {
    m_start = std::make_pair(x, y);
}

void Maze::setEndingLocation(int x, int y) {
    m_end = std::make_pair(x, y);
}

// Navigate to the specified exit
void Maze::findExit() {

    int row, col;
    m_mazeStack.push(m_start.first, m_start.second);

    while (m_current != m_end) {

        row = m_current.first;
        col = m_current.second;

        // Up: row - 1
        if (moveUp(row, col) && !previouslyVisited(std::make_pair(row-1, col))) {

            m_mazeStack.push(row - 1, col);
        }
            // Down: row + 1
        else if (moveDown(row, col) && !previouslyVisited(std::make_pair(row+1, col))) {

            m_mazeStack.push(row + 1, col);
        }
            // Left: col - 1
        else if (moveLeft(row, col) && !previouslyVisited(std::make_pair(row, col-1))) {

            m_mazeStack.push(row, col - 1);
        }
            // Right: col + 1
        else if (moveRight(row, col) && !previouslyVisited(std::make_pair(row, col+1))) {

            m_mazeStack.push(row, col + 1);
        }
            // Backtrack - No other valid directions
        else {

            m_mazeStack.pop();
        }

        // Move to the location at the top of the stack
        m_current = m_mazeStack.peek();

        // Record visiting this space
        m_visitedSpaces.push_back(m_current);

        // If the m_end of the maze cannot be reached
        if (m_mazeStack.isEmpty()) {

            std::cout << "Stack is empty, could not find exit." << std::endl;
            break;
        }
    }

    displayExitPath();
}

// Check to see if this space has been visited before
bool Maze::previouslyVisited(std::pair<int,int> pair) {

    // If the pair is in the visitedSpace vector
    return std::find(m_visitedSpaces.begin(), m_visitedSpaces.end(), pair) != m_visitedSpaces.end();
}

// Directionals - True if coord is not out of bounds and next move is not a wall
bool Maze::moveUp(int x, int y) {

    return x > 0 && m_maze[x - 1][y] != '+' && m_maze[x - 1][y] != '-' && m_maze[x - 1][y] != '|';
}

bool Maze::moveDown(int x, int y) {

    return x < m_ROW_SIZE && m_maze[x + 1][y] != '+' && m_maze[x + 1][y] != '-' && m_maze[x + 1][y] != '|';
}

bool Maze::moveLeft(int x, int y) {

    return y > 0 && m_maze[x][y - 1] != '+' && m_maze[x][y - 1] != '-' && m_maze[x][y - 1] != '|';
}

bool Maze::moveRight(int x, int y) {

    return y < m_COL_SIZE && m_maze[x][y + 1] != '+' && m_maze[x][y + 1] != '-' && m_maze[x][y + 1] != '|';
}