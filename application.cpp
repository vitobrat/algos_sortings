#include "application.h"
#include <iostream>
#include "list.h"
#include "array.h"
#include "quicksort.h"
#include "timsort.h"

using namespace std;

Application::Application()
= default;

void Application::exec(){
    int type;
    cout << "1 - Timsort\n2 - Quicksort\n";
    cin >> type;
    string str;
    auto *arr = new Array;
    cout << "Length: ";
    int length;
    cin >> length;
    if (type == 1){
        arr->createArr(length);
        arr->printArr();
        cout << "After Timsort - ";
        TimSort::sort(*arr);
        arr->printArr();
    }else if(type == 2){
        arr->createArr(length);
        arr->printArr();
        cout << "After quicksort - ";
        QuickSort::quickSort(arr->arr, 0, arr->getSize() - 1);
        arr->printArr();
    }
    delete arr;
}
