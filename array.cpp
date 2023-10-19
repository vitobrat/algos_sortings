#include "array.h"
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

Array::Array(){

}

Array::~Array(){
    delete []arr;
    size = 0;
}

int Array::getSize() const{
    return size;
}

void Array::printArr() const{
    cout << "Array: ";
    for(int *i = arr; i != arr + size; i++){
        cout << *i << " ";
    }
    cout << "\n";
}

void Array::createArr(unsigned N){
    deleteArr();
    size = N;
    arr = new int[size];
    srand(time(NULL));
    for (int i = N - 1; i >= 0; i--){
        arr[i] = rand() % 10000 - 5000;
    }
}

void Array::createArr(string str){
    deleteArr();
    istringstream iss(str);
    int num;
    while (iss >> num) {
        addValueAtArr(size + 1, num);
    }
}

void Array::addValueAtArr(int index, int value){
    if (!(index >= 1 && index <= size + 1)){
        return;
    }
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


void Array::changeValueAtArray(int index1, int index2){
    if (!((index1 >= 1 && index1 <= size) && (index2 >= 1 && index2 <= size))){
        cout << "Wrong input! Try again.\n";
        return;
    }  
    swap(arr[index2 - 1], arr[index1 - 1]);
}

int Array::getValueAtArrByIndex(int index) const{
    if (index >= 0 && index <= size) return arr[index];
}

int Array::getValueAtArrByValue(int value) const{
    int index, count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
}

void Array::deleteValueAtArr(int index){
    if (!(index >= 1 && index <= size)){
        return;
    }
    int *arr1 = new int[size - 1];
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
}

int Array::operator[](int index) const{
    return arr[index];
}

Array& Array::operator=(const Array &arr){
    if (this != &arr) {  // Проверка на самоприсваивание
        this->arr = arr.arr;
    }
    return *this;
}

void Array::deleteArr(){
    delete []arr;
    size = 0;
}
