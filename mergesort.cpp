#include "mergesort.h"
#include <cmath>

MergeSort::MergeSort()
{

}


int*  copy(const int arr[], int left, int right){
    int *arrCopy = new int[right - left];
    for (int i = left; i < right; i++){
        arrCopy[i - left] = arr[i];
    }
    return arrCopy;
}

void merge(int arr[], int left, int medium, int right){
    int N1 = medium + 2 - left;
    int N2 = right + 1 - medium;
    int *arrLeft = copy(arr, left, medium + 1);
    int *arrRight = copy(arr, medium + 1, right + 1);
    arrLeft[N1 - 1] = INFINITY;
    arrRight[N2 - 1] = INFINITY;
    int i = 0, j = 0, k = left;
    while(i < N1 - 1 || j < N2 - 1){
        if (arrLeft[i] < arrRight[j]){
            arr[k++] = arrLeft[i++];
        }else{
            arr[k++] = arrRight[j++];
        }
    }
}

void MergeSort::mergeSort(int arr[], int left, int right){
    if (left < right){
        int medium = (left + right) / 2;
        mergeSort(arr, left, medium);
        mergeSort(arr, medium + 1, right);
        merge(arr, left, medium, right);
    }
}
