#ifndef STRUCT_TYPE_PROJECT_N_H
#define STRUCT_TYPE_PROJECT_N_H

#include <iostream>

using namespace std;

// Опис елемента структури даних
struct Node
{
    int data;
    Node* next;
};

// Основні операції
void addElement(Node*& head, int value);
void deleteElement(Node*& head, int value);
void printStructure(Node* head);
bool searchElement(Node* head, int value);

#endif
