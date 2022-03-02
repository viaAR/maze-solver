#ifndef A2_MAZE_NODE_H
#define A2_MAZE_NODE_H

#include <iostream>
#include <utility>

class Node {
public:
    // Coordinates are represented with the pair data structure
    std::pair<int, int> m_pair {-1, -1};
    Node* m_next {nullptr};
};


#endif