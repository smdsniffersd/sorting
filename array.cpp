#include "array.h"
// Constructors
array2024::array2024(size_t n) : data(nullptr), size_(0) {
    resize(n);
}

array2024::array2024(const array2024& A) : data(nullptr), size_(0) {
    if (A.data && resize(A.size_)) {
        for (size_t i = 0; i < size_; ++i) {
            data[i] = A.data[i];
        }
    }
}

array2024::array2024(array2024&& A) noexcept : data(A.data), size_(A.size_) {
    A.data = nullptr;
    A.size_ = 0;
}

array2024::~array2024() {
    resize(0);
}

// Operators
array2024& array2024::operator=(const array2024& A) {
    if (this != &A) {
        if (A.data && resize(A.size_)) {
            for (size_t i = 0; i < size_; ++i) {
                data[i] = A.data[i];
            }
        }
        else {
            resize(0);
        }
    }
    return *this;
}

array2024& array2024::operator=(array2024&& A) noexcept {
    if (this != &A) {
        delete[] data;
        data = A.data;
        size_ = A.size_;
        A.data = nullptr;
        A.size_ = 0;
    }
    return *this;
}

float& array2024::operator()(size_t i) {
    if (i == 0 || i > size_) {
        throw std::out_of_range("Invalid index in operator()");
    }
    return data[i - 1];
}

const float& array2024::operator()(size_t i) const {
    if (i == 0 || i > size_) {
        throw std::out_of_range("Invalid index in operator()");
    }
    return data[i - 1];
}

// Methods
bool array2024::resize(size_t new_size) {
    if (new_size == size_) {
        return true;
    }
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
        size_ = 0;
    }
    if (new_size > 0) {
        try {
            data = new float[new_size];
            size_ = new_size;
        }
        catch (...) {
            return false;
        }
    }
    return true;
}

bool array2024::generate(float inf, float sup) {
    if (size_ == 0 || data == nullptr) {
        return false;
    }
    float K = (sup - inf) / RAND_MAX;
    for (size_t i = 0; i < size_; ++i) {
        data[i] = inf + std::rand() * K;
    }
    return true;
}

void array2024::clear() {
    resize(0);
}

void array2024::invert() {
    if (size_ == 0 || data == nullptr) {
        return;
    }
    for (size_t i = 0; i < size_ / 2; ++i) {
        float tmp = data[i];
        data[i] = data[size_ - 1 - i];
        data[size_ - 1 - i] = tmp;
    }
}

void array2024::swap(size_t i, size_t j) {
    if (size_ == 0 || data == nullptr || i == 0 || j == 0 || i > size_ || j > size_) {
        throw std::out_of_range("Index out of range in swap");
    }
    float tmp = data[i - 1];
    data[i - 1] = data[j - 1];
    data[j - 1] = tmp;
}

void array2024::print() const {
    if (size_ == 0 || data == nullptr) {
        std::cout << "Array is empty\n";
        return;
    }
    for (size_t i = 0; i < size_; ++i) {
        std::cout << data[i] << ", ";
        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void array2024::SaveToFile(const char* filename) {
    if (size_ == 0 || data == nullptr) {
        return;
    }
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing");
    }
    for (size_t i = 0; i < size_; ++i) {
        file << data[i];
        if (i < size_ - 1) {
            file << '\n';
        }
    }
}

void array2024::LoadFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        return;
    }
    size_t n = 0;
    float tmp;
    while (file >> tmp) {
        ++n;
    }
    file.clear();
    file.seekg(0);
    if (resize(n)) {
        for (size_t i = 0; i < size_; ++i) {
            file >> data[i];
        }
    }
}

size_t array2024::size() const {
    return size_;
}