#pragma once
#include "array.h"

void Heap_sort(array2024& A, bool f);
void correct(array2024& A, size_t p, size_t n);
void build(array2024& A);



void Heap_sort(array2024& A) {
    size_t i;
    build(A);  // ���������� ����

    // ����������
    for (i = A.size(); i > 1; --i) {
        A.swap(1, i);  // ���������� �������� ������� � �����
        correct(A, 1, i - 1);  // ��������������� �������� ����
    }
}

void correct(array2024& A, size_t p, size_t n) {
    size_t l = 2 * p;      // ����� �������� �������
    size_t r = 2 * p + 1;  // ������ �������� �������
    size_t m = p;          // ������ ������������� ��������

    // ��������� ����� �������� �������
    if (l <= n && A(m) < A(l)) {
        m = l;
    }

    // ��������� ������ �������� �������
    if (r <= n && A(m) < A(r)) {
        m = r;
    }

    // ���� ������������ ������� �� �������, ������ �� ������� � ���������� ������������
    if (m != p) {
        A.swap(m, p);
        correct(A, m, n);
    }
}

void build(array2024& A) {
    size_t N = A.size();
    for (size_t n = N / 2; n > 0; --n) {
        correct(A, n, N);
    }
}