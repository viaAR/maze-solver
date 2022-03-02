#ifndef A2_MAZE_STACK_H
#define A2_MAZE_STACK_H

#include <iostream>
#include <utility>
#include "Node.h"

class Stack {
private:
    Node* m_top {nullptr};

public:
    Stack() = default;
    virtual ~Stack();

    void push(int x, int y);
    std::pair<int, int> peek();
    void pop();
    bool isEmpty();
};


#endif
