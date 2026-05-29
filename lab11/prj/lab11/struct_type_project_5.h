#ifndef STRUCT_TYPE_PROJECT_5_H
#define STRUCT_TYPE_PROJECT_5_H

#include <iostream>
#include <string>

using namespace std;

struct EducationRegistry
{
    int edeboCode;
    string fullName;
    string address;
    string phone;
    string email;
    int foundationYear;
};

struct Node
{
    EducationRegistry data;
    Node* next;
};

void addRecord(Node*& head, EducationRegistry newRecord);
void printRegistry(Node* head);

#endif
