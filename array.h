#ifndef ARRAY_H
#define ARRAY_H
#include <string>

using namespace std;

class Array
{
    int size = 0;
public:
    Array();
    int *arr = nullptr;
    int getSize();
    void printArr();
    void createArr(unsigned N);
    void createArr(string str);
    void addValueAtArr(int index, int value);
    void changeValueAtArray(int index1, int index2);
    int getValueAtArrByIndex(int index);
    int getValueAtArrByValue(int value);
    void deleteValueAtArr(int index);
    void deleteArr();
};

#endif // ARRAY_H
