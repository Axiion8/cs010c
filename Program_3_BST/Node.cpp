#include "Node.h"

Node::Node(string key) {
    count = 1;
    data = key;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

string Node::getString() const {
    return data;
}

void Node::add() {
    count = count + 1;
}

void Node::sub() {
    count = count - 1;
} 