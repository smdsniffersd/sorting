#pragma once
#include "stack.h"
#include "array.h"
#include <limits>

void merge(array2024& a, size_t L, size_t m, size_t R);

void merge_Sort(array2024& a, size_t L, size_t R) {
    if (L >= R) return;
    size_t m = L + (R - L) / 2;
    merge_Sort(a, L, m);
    merge_Sort(a, m + 1, R);
    merge(a, L, m, R);
}

void merge(array2024& a, size_t L, size_t m, size_t R) {
    size_t n1 = m - L + 1; // Размер левого подмассива
    size_t n2 = R - m;     // Размер правого подмассива
    fstack Left, Right;

    // Копируем элементы в обратном порядке
    for (size_t i = n1; i > 0; i--) {
        Left.push(a(L + i - 1));
    }
    for (size_t j = n2; j > 0; j--) {
        Right.push(a(m + j));
    }

    // Слияние
    size_t k = L;
    while (k <= R) {
        if (Left.empty() || (!Right.empty() && Right.read() < Left.read())) {
            a(k) = Right.read();
            Right.pop();
        }
        else {
            a(k) = Left.read();
            Left.pop();
        }
        k++;
    }
}