#pragma once
#include "quickSort.h"
#include "array.h"
#include <random>

// Генерирует случайное целое число в диапазоне [i, j]
size_t rand(size_t i, size_t j) {
    static std::random_device rd;  // Источник энтропии
    static std::mt19937 gen(rd()); // Генератор Mersenne Twister
    std::uniform_int_distribution<size_t> dist(i, j); // Равномерное распределение
    return dist(gen);
}

size_t Partition(array2024& a, size_t p, size_t r);
size_t rand_Partition(array2024& a, size_t p, size_t r);


void rand_QuickSort(array2024& a, size_t p, size_t r) {
    if (p < r) {
        size_t q = rand_Partition(a, p, r);
        rand_QuickSort(a, p, q - 1);
        rand_QuickSort(a, q + 1, r);
    }
}

size_t rand_Partition(array2024& a, size_t p, size_t r) {
    size_t i = rand(p, r);
    a.swap(r, i);
    return Partition(a, p, r);
}


size_t Partition(array2024& a, size_t p, size_t r) {
    float x = a(r);
    size_t i = p - 1;
    for (size_t j = p; j < r; j++) {
        if (a(j) <= x) {
            i++;
            a.swap(i, j);
        }
    }
    a.swap(i + 1, r);
    return i + 1;
}