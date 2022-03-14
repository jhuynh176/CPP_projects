#ifndef LINKED_LIST_FUNCTIONALITY_PROJECT_H
#define LINKED_LIST_FUNCTIONALITY_PROJECT_H


#include <string>

struct StringNode {
    std::string data;
    StringNode* next;
    StringNode(std::string data): data(std::move(data)), next(nullptr) {}
};


#endif //LINKED_LIST_FUNCTIONALITY_PROJECT_H
