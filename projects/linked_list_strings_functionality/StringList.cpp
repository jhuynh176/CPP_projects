//
// Created by Hieu on 4/12/2020.
//

//File Name: assign5_hth9.cpp
//
//Author: Hieu Huynh
//Date: 4/12/2020
//Assignment Number: 5
//CS 2308.255 Spring 2020
//Instructor: Vladyslav Prokopenko
//
//Description: This program is able to show, search, write a functionality for a linked list of strings.

#include <algorithm>
#include<string>
#include "StringList.h"

using namespace std;


StringList::StringList() : head(nullptr) {}

StringList::StringList(const vector<string>& stringVector) {
    if (stringVector.empty())
        this->head = nullptr;
    else {
        this->head = new StringNode(stringVector[0]);
        StringNode* node = this->head;
        for (int i = 1; i < stringVector.size(); ++i) {
            node->next = new StringNode(stringVector[i]);
            node = node->next;
        }
    }

}

void StringList::swapNodes(StringNode*& previousNext, StringNode* node1, StringNode* node2) {
    node1->next = node2->next;
    node2->next = node1;
    previousNext = node2;
}

void StringList::bubbleSort() {
    if (this->head == nullptr || this->head->next == nullptr)
        return;

    bool swapped;
    do {
        swapped = false;
        StringNode* prevNode = this->head;
        StringNode* currNode = this->head;

        // Handle case when we want to change the first node
        if (currNode->data > currNode->next->data) {
            StringList::swapNodes(this->head, currNode, currNode->next);
            swapped = true;
        }
        currNode = currNode->next;

        // Standard bubble sort, iterate until the end of list is reached, swap if out of order
        while (currNode->next != nullptr) {
            if (currNode->data > currNode->next->data) {
                // swap nodes
                StringList::swapNodes(prevNode->next, currNode, currNode->next);
                swapped = true;

                // because we have swapped currNode with the next one
                // so we don't need to update it like this currNode = currNode->next;
                prevNode = prevNode->next;
            }
            else {
                prevNode = prevNode->next;
                currNode = currNode->next;
            }
        }
    } while (swapped);
}

bool StringList::operator==(const StringList& other) {
    bool equal = true;
    StringNode* thisNode = this->head;
    StringNode* otherNode = other.head;

    while (thisNode != nullptr && otherNode != nullptr) {
        if (thisNode->data != otherNode->data) {
            equal = false;
            break;
        }
        thisNode = thisNode->next;
        otherNode = otherNode->next;
    }
    if (thisNode != nullptr || otherNode != nullptr)
        equal = false;
    return equal;
}

void StringList::pushBack(string s) {
    auto newNode = new StringNode(s);

    if (this->head == nullptr) {
        this->head = newNode;
    }
    else {
        StringNode* node = this->head;
        while (node->next != nullptr)
            node = node->next;
        node->next = newNode;
    }
}

void StringList::popBack() {
    if (this->head == nullptr) {
        // do nothing
    }
    else if (this->head->next == nullptr) {
        delete this->head;
        this->head = nullptr;
    }
    else {
        StringNode* node = this->head;
        while (node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }
}

string StringList::back() {
    string result;

    if (this->head != nullptr) {
        StringNode* node = this->head;
        for (; node->next != nullptr; node = node->next) {}
        result = node->data;
    }
    return result;
}


void StringList::swap(StringList& other) {
    std::swap(this->head, other.head);
}

StringList& StringList::operator=(StringList other) {
    this->swap(other);
    return *this;
}

StringList::StringList(const StringList& other)
{
    
    if (other.head == NULL) {
        head = NULL;
    }
    else {
        head = new StringNode(other.head->data);
        head->data =other.head->data;
        
        StringNode* pNewNode = head;
        StringNode* pOldNode = other.head->next;

        while (pOldNode != NULL) {
            pNewNode->next = new StringNode(other.head->data);
            pNewNode = pNewNode->next;
            pNewNode->data = pOldNode->data;
            pOldNode = pOldNode->next;
        }
        pNewNode->next = NULL;
    }
}

StringList::~StringList()
{
    StringNode* p = head;

    while (p != NULL) {
        head = head->next; 
        delete p; 
        p = head; 
    }
    head = NULL;
}

std::string StringList::concatenate(const std::string& separator)
{
    string result = "";
    StringNode* current = head;

    while (current != nullptr)
    {
        if (current->next == NULL)
        {
            result += current->data;
        }
        else
        {
            result += current->data + separator;
        }
        current = current->next;

    }
    return result;
}


std::string StringList::toString()
{
    string result = "";
    StringNode* current = head;
    while (current != nullptr)
    {
        if (current->next == NULL)
        {
            result += current->data;
        }
        else
        {
            result += current->data + '\n';
        }
        current = current->next;

    }
    return result;
}

void StringList::pushFront(std::string s)
{
    StringNode* new_node = new StringNode(s);

    new_node->data = s;
    new_node->next = head;
    head = new_node;
}

void StringList::popFront()
{
    if (head)
    {
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }
}

std::string StringList::front()
{
    if (head)
    {
        StringNode* temp = head;
        return temp->data;
    }
    else
        return "";
}

StringList StringList::operator+(const StringList& other)
{
    if (this->head==nullptr) 
        return other;

    if (other.head == nullptr)
        return *this;
    
    StringList* ret_list = this;

    StringNode* temp = other.head;

    
    while (temp != nullptr) 
    {     
        ret_list->pushBack(temp->data);
        temp = temp->next;
    }

    return *ret_list;
    
}

void StringList::reverse()
{
    StringNode* current = head;
    StringNode* prev = NULL, * next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

bool StringList::insert(std::string s, int position)
{
    StringNode* newNode = new StringNode(s);
    if (position == 0) 
    {
        newNode->next = head;
        return newNode;
        return true;
    }

    StringNode* cur = head;
    int curPos = 0;
    while (curPos != position - 1) 
    {
        cur = cur->next;
        curPos += 1;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    return head;
    return true;
}

bool StringList::remove(int position)
{
    StringNode* prev=head;
    int number = 0;

        if (position < 0)
            return false;

        if (position == 0)
        {
            head = head->next;
            delete head;
            return true;
        }

        for (int i = 0; prev != NULL && i < position - 1; i++)
            prev = prev->next;

        if (prev == NULL || prev->next == NULL)
            return false;

        StringNode* next = prev->next->next;
        delete prev->next;
        prev->next = next;
        return true;
}