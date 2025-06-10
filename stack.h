#pragma once
#include <cmath>

class fstack {
public:
    fstack();
    ~fstack();
    size_t count_element() const { return size; }
    void push(float n);
    void pop();
    bool empty() const { return size == 0; }
    float read() const { return A[size - 1]; }  // Исправлено
    void resize();

private:
    size_t capacity, size;
    float* A;
};

