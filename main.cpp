#include <iostream>
#include "simpleSort.h"
#include "array.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include "intro.h"

using namespace std;

int main() {
    
	setlocale(LC_ALL, ".1251");


	intro();
	clock_t t;
	size_t size_, var = 1;
	size_t size_factor = 30000 * var;
	size_t iter_count = 30;
	size_ = size_factor;
	iter_count = iter_count++;

	float totalrand_QuickSortTime = 0.0f;
	float totalmerge_SortTime = 0.0f;
	float totalHeap_sortTime = 0.0f;


	array2024 A(size_), B(size_), rand_QuickSortTime(iter_count), merge_SortTime(iter_count), Heap_sortTime(iter_count), Size(iter_count), Iterations(iter_count);

	A.generate(0.1, 2);


	for (size_t iter = 0; iter < iter_count; ++iter) {
		progressbar(iter, iter_count);
		size_t size = size_factor * iter;
		Size(iter + 1) = size;
		Iterations(iter + 1) = iter;
		B = A;
		t = clock();
		rand_QuickSort(B, 1, B.size());
		t = clock() - t;
		totalrand_QuickSortTime += float(t) / CLOCKS_PER_SEC;
		rand_QuickSortTime(iter + 1) = totalrand_QuickSortTime;
	}
	for (size_t iter = 0; iter < iter_count; ++iter) {
		progressbar(iter, iter_count);
		B = A;
		t = clock();
		merge_Sort(B, 1, B.size());
		t = clock() - t;
		totalmerge_SortTime += float(t) / CLOCKS_PER_SEC;
		merge_SortTime(iter + 1) = totalmerge_SortTime;
	}
	for (size_t iter = 0; iter < iter_count; ++iter) {
		progressbar(iter, iter_count);
		B = A;
		t = clock();
		Heap_sort(B);
		t = clock() - t;
		totalHeap_sortTime += float(t) / CLOCKS_PER_SEC;
		Heap_sortTime(iter + 1) = totalHeap_sortTime;
	}



	rand_QuickSortTime.SaveToFile("rand_QuickSortTime.txt");
	merge_SortTime.SaveToFile("merge_SortTime.txt");
	Heap_sortTime.SaveToFile("InsertSortTime.txt");
	Iterations.SaveToFile("Iterations.txt");
	Size.SaveToFile("Size.txt");











    return 0;
}