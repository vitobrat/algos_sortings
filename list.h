#ifndef LIST_H
#define LIST_H
#include "iostream";

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
    void addValueAtList();
    void changeValueAtList();
    void getValueAtList();
    void deleteValueAtList();
    void deleteList ();
};

#endif // LIST_H
