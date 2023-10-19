#include "application.h"
#include <iostream>
#include "list.h"
#include "array.h"
#include "mergesort.h"
#include "timsort.h"

using namespace std;

Application::Application()
{

}

void Application::exec(){
    int type;
    cout << "1 - Timsort\n2 - Mergesort\n";
    cin >> type;
    string str;
    Array *arr = new Array;
    cout << "Length: ";
    int length;
    cin >> length;
    if (type == 1){
        arr->createArr(length);
        arr->printArr();
        cout << "After Timsort sort - ";
        TimSort::sort(*arr);
        arr->printArr();
    }else if(type == 2){
        arr->createArr(length);
        arr->printArr();
        cout << "After merge sort - ";
        MergeSort::mergeSort(arr->arr, 0, arr->getSize() - 1);
        arr->printArr();
    }
    delete arr;
}
