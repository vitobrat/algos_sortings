#ifndef ARRAY_H
#define ARRAY_H
#include <string>

using namespace std;

class Array
{
public:
    Array();
    int *arr = nullptr;
    int size = 0;
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
