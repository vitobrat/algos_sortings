#include <algorithm>
#include "quicksort.h"

using namespace std;

QuickSort::QuickSort()
= default;


void QuickSort::quickSort(int arr[], int low, int high){
    int i = low, j = high;
    int pivot = arr[(j+i)/2];
    while (i <= j){
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}
