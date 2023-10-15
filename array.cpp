#include "array.h"
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

Array::Array(){

}



void Array::printArr(){
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "Array: ";
    for(int *i = arr; i != arr + size; i++){
        cout << *i << " ";
    }
    cout << "\n";
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to print element in array in nanoseconds: " << end - start << "ns\n";
}

void Array::createArr(unsigned N){
    deleteArr();
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    size = N;
    arr = new int[size];
    srand(time(NULL));
    for (int i = N - 1; i >= 0; i--){
        arr[i] = rand() % 100;
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to creat array in nanoseconds: " << end - start << "ns\n";
}

void Array::createArr(string str){// переделать(size неизвестен)
    deleteArr();
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    istringstream iss(str);
    int num;
    while (iss >> num) {
        addValueAtArr(size + 1, num);
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to creat array in nanoseconds: " << end - start << "ns\n";
}

void Array::addValueAtArr(int index, int value){
    if (size == 0){
        arr = new int[1];
        arr[0] = value;
        size++;
        return;
    }
    int *arr1 = new int[size + 1];
    for(int i = 0, j = 0; i < size + 1; i++, j++){
        if(i == index - 1){
            arr1[i] = value;
            j--;
        }else{
            arr1[i] = arr[j];
        }

    }
    delete []arr;
    arr = arr1;
    size++;
}

void Array::addValueAtArr(){
    cout << "Input new index: ";
    int index;
    cin >> index;
    if (!(index >= 1 && index <= size + 1)){
        cout << "Wrong input! Try again.\n";
        return;
    }
    cout << "Input new value: ";
    int value;
    cin >> value;
    int *arr1 = new int[size + 1];
    for(int i = 0, j = 0; i < size + 1; i++, j++){
        if(i == index - 1){
            arr1[i] = value;
            j--;
        }else{
            arr1[i] = arr[j];
        }

    }
    delete []arr;
    arr = arr1;
    size++;
}


void Array::changeValueAtArray(){
    cout << "Input 2 indexes you wanna change(by enter):";
    int index1;
    cin >> index1;
    int index2;
    cin >> index2;
    if (!((index1 >= 1 && index1 <= size) && (index2 >= 1 && index2 <= size))){
        cout << "Wrong input! Try again.\n";
        return;
    }
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    swap(arr[index2 - 1], arr[index1 - 1]);
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to change element in array in nanoseconds: " << end - start << "ns\n";
}

void Array::getValueAtArrByIndex(int index){
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if (index <= size) cout << "Value with index "<< index << " - " << arr[index - 1] << "\n";
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to get element in array in nanoseconds: " << end - start << "ns\n";
}

void Array::getValueAtArrByValue(){
    cout << "Which type do you want to get element\n"<<
        "1)by value\n"
        "2)by index\n";
    int type, value, index, count = 0;
    cin >> type;
    switch (type) {
    case 1:
    {
        cout << "Input value:";
        cin >> value;
        auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        for(int i = 0; i < size; i++){
            if(arr[i] == value){
                cout << "The array contain an element - " << value << "(index - " << i+1 << ")" << "\n";
                return;
            }
        }
        cout << "The array does not contain an element - " << value << "\n";
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "time spent to get element in array in nanoseconds: " << end - start << "ns\n";
    }
    case 2:
        cout << "Input index:";
        cin >> index;
        getValueAtArrByIndex(index);
        break;
    default:
        cout << "Wrong input! Try again.\n";
        getValueAtArrByValue();
        break;
    }

}

void Array::deleteValueAtArr(){
    int *arr1 = new int[size - 1];
    cout << "Input index:";
    int index ;
    cin >> index;
    while (!(index >= 1 && index <= size)){
        cout << "Wrong input! Try again.\n";
        cin >> index;
    }
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for(int i = 0, j = 0; i < size; i++, j++){
        if(i == index - 1){
            j--;
        }else{
            arr1[j] = arr[i];
        }
    }
    delete []arr;
    arr = arr1;
    size--;
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to delete element in array in nanoseconds: " << end - start << "ns\n";
}

void Array::deleteArr(){
    delete []arr;
    size = 0;
}
