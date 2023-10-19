#ifndef LIST_H
#define LIST_H
#include "iostream"

using namespace std;

class List
{
public:
    int data = 0;
    int size = 0;
    List *head = nullptr;
    List *next = nullptr;
    List *prev = nullptr;
    List();
    void printList();
    void createList(unsigned N);
    void createList(string str);
    List *listItem(unsigned int index);
    void addValueAtList(int index, int value);
    void changeValueAtList(int index1, int index2);
    int getValueAtListByValue(int value);
    int getValueAtListByIndex(int index);
    void deleteValueAtListByValue(int value);
    void deleteValueAtListByIndex(int index);
    void deleteList ();
};

#endif // LIST_H
