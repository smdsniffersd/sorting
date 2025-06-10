#include "stack.h"
#include <iostream>
using namespace std;

fstack::fstack() {
    size = 0;
    capacity = 1;
    A = new float[capacity];
}

fstack::~fstack() {
    delete[] A;
}

void fstack::push(float n) {
    if (size == capacity) {
        resize();
        if (size == capacity) { // ��������, ������� �� ��������� ����������
            throw std::runtime_error("Failed to resize stack");
        }
    }
    A[size] = n;
    size++;
}


void fstack::pop() {
    if (size == 0) {
        resize(); // ����������������� ��� ������ �����
        return;
    }
    size--;
    if (size == 0) {
        resize(); // ������� ������ ��� ������ �����������
    }
}


void fstack::resize() {
    if (size == capacity) {
        capacity *= 2;
        float* B = new float[capacity];
        for (size_t i = 0; i < size; i++) {
            B[i] = A[i];
        }
        delete[] A;
        A = B;
    }
    else if (size == 0 && capacity > 0) {
        delete[] A;
        A = new float[1]; // ����������� ������� 1
        capacity = 1;
    }
}