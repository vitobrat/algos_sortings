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
    void addValueAtArr();
    void addValueAtArr(int index, int value);
    void changeValueAtArray();
    void getValueAtArrByIndex(int index);
    void getValueAtArrByValue();
    void deleteValueAtArr();
    void deleteArr();
};

#endif // ARRAY_H
