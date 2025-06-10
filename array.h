#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdexcept>

class array2024 {
private:
    float* data;
    size_t size_;

public:
    // Constructors
    array2024(size_t n = 0);
    array2024(const array2024& A);
    array2024(array2024&& A) noexcept;
    ~array2024();

    // Operators
    array2024& operator=(const array2024& A);
    array2024& operator=(array2024&& A) noexcept;
    float& operator()(size_t i);
    const float& operator()(size_t i) const;

    // Methods
    bool resize(size_t new_size);
    bool generate(float inf = 0.0f, float sup = 1.0f);
    void clear();
    void invert();
    void swap(size_t i, size_t j);
    void print() const;
    void SaveToFile(const char* filename);
    void LoadFromFile(const char* filename);
    size_t size() const;
};