#include "Stack.h"

Stack::~Stack() {}

// Create a new node and push it onto the stack
void Stack::push(int x, int y) {

    Node* new_node = new Node();
    new_node->m_pair = std::make_pair(x, y);

    new_node->m_next = m_top;
    m_top = new_node;
}

// Peek at the top node on the stack
std::pair<int, int> Stack::peek() {

    if (!isEmpty()) {

        return m_top->m_pair;
    }
    else {

        return std::pair<int, int>(-1, -1);
    }
}

// Pop the top node on the stack
void Stack::pop() {
    if (!isEmpty()) {

        Node* temp = m_top;

        m_top = m_top->m_next;

        delete temp;
    }
}

// Determine if the stack is empty
bool Stack::isEmpty() {
    return m_top == nullptr;
}
