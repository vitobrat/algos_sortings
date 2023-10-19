#include "timsort.h"

TimSort::TimSort()
{

}


int calcMinRun(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r |= (n & 1); // Поддерживаем четность.
        n >>= 1;      // Делим размер массива на 2.
    }
    return n + r; // Возвращаем минимальный "run".
}

// Дополнительная функция для бинарного поиска в режиме "галопа"
int binarySearch(Array &arr, int start, int len, int target) {
    int lo = start;
    int hi = len;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr.arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo - start;
}

void merge(Array &arr, int left, int mid, int right) {
    int len1 = mid - left;
    int len2 = right - mid;


    auto *leftArr = new Array;
    leftArr->createArr(len1);
    auto *rightArr = new Array;
    rightArr->createArr(len2);


    for (int i = 0; i < len1; i++) {
        leftArr->arr[i] = arr[left + i];
    }
    for (int i = 0; i < len2; i++) {
        rightArr->arr[i] = arr[mid + i];
    }

    int i = 0, j = 0, k = left;
    int consecutiveCopiesL = 0, consecutiveCopiesR = 0; // Счетчик последовательных копирований
    bool galloping = false;    // Флаг режима "галопа"

    while (i < len1 && j < len2) {
        if (leftArr->arr[i] <= rightArr->arr[j]) {
            arr.arr[k++] = leftArr->arr[i++];
            consecutiveCopiesL++;
            consecutiveCopiesR = 0;
            if (consecutiveCopiesL >= 7 && !galloping) {
                // Включаем режим "галопа" и используем бинарный поиск
                int searchIdx = binarySearch(*leftArr, i, len1, rightArr->arr[j]);
                int x = i;
                for(; x < searchIdx; x++) {
                    arr.arr[k++] = leftArr->arr[i++];
                }
                galloping = true;
                consecutiveCopiesL=0;
            }
        } else {
            arr.arr[k++] = rightArr->arr[j++];
            consecutiveCopiesR++;
            consecutiveCopiesL=0;
            if (consecutiveCopiesR >= 7 && !galloping) {
                // Включаем режим "галопа" и используем бинарный поиск
                int searchIdx = binarySearch(*rightArr, j, len2, leftArr->arr[i]);
                int x = j;
                for(; x < searchIdx; x++) {
                    arr.arr[k++] = rightArr->arr[j++];
                }
                galloping = true;
                consecutiveCopiesR = 0;
            }
        }
    }

    while (i < len1) {
        arr.arr[k++] = leftArr->arr[i++];
    }

    while (j < len2) {
        arr.arr[k++] = rightArr->arr[j++];
    }
}

void insertionSort(Array &arr, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr.arr[j + 1] = arr[j];
            j--;
        }
        arr.arr[j + 1] = key;  // Сортировка вставкой для небольших подмассивов.
    }
}

void TimSort::sort(Array &arr) {
    int n = arr.getSize();
    if (n < 2)
        return;

    int minRun = calcMinRun(n); // Вычисляем минимальный размер "run" на основе размера массива.

    for (int i = 0; i < n; i += minRun) {
        int end = std::min(i + minRun, n);
        insertionSort(arr, i, end);  // Сортировка вставкой небольших подмассивов (минимальных "run").
    }

    for (int size = minRun; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size, n);
            int right = std::min(left + 2 * size, n);
            if (mid != right)
                merge(arr, left, mid, right);  // Объединение подмассивов с использованием Merge Sort.
        }
    }

}
