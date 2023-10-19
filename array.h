#ifndef ARRAY_H
#define ARRAY_H
#include <string>

using namespace std;

class Array
{
    int size = 0;
public:
    Array();
    ~Array();
    int *arr = nullptr;
    int getSize() const;
    void printArr() const;
    void createArr(unsigned N);
    void createArr(const string& str);
    void addValueAtArr(int index, int value);
    void changeValueAtArray(int index1, int index2) const;
    int getValueAtArrByIndex(int index) const;
    int getValueAtArrByValue(int value) const;
    void deleteValueAtArr(int index);
    int operator[](int index) const;
    Array& operator=(const Array &arr);
    void deleteArr();
};

#endif // ARRAY_H
