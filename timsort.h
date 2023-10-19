#ifndef TIMSORT_H
#define TIMSORT_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "array.h"
#include "mergesort.h"

const int MIN_MERGE = 64;  // Минимальный размер "run", используемый в Timsort.

class TimSort {
public:
    static void sort(Array &arr);
    TimSort();
};

#endif // TIMSORT_H
