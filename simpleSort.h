#pragma once
#include "array.h"

void BubbleSort(array2024& A) {

    size_t n = A.size();
    if (n == 0) return;
    for (size_t j = 0; j < n - 1; ++j) {
        for (size_t i = 1; i < n - j; ++i) {
            if (A(i + 1) < A(i)) {
                A.swap(i, i + 1);
            }
        }
    }
}


void SelectSort(array2024& A) {
    size_t n = A.size();
    if (n == 0) return;
    size_t i, pos;
    float temp;
    for (n = A.size(); n > 0; --n) {
        for (pos = 1, temp = A(pos), i = 2; i <= n; ++i) {
            if (A(i) < temp) {
                pos = i;
                temp = A(i);
            }
        }
        A.swap(pos, n);
    }
}


void InsertSort(array2024& A) {
    size_t n = A.size();
    if (n == 0) return;
    size_t i, j;

    for (i = 2; i <= n; ++i) {
        j = i;
        while (j > 1 && A(j - 1) > A(j)) {
            A.swap(j, j - 1);
            --j;
        }
    }
}