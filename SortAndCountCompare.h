#pragma once

// the Sorting algorithm here is similar to the Sorting algorithm 
// the algorithm here aslo count the number of comparison while running the function


// ----------------- ALL SORTING ALGORITHM -----------------------------
// Insertion Sort algorithm
void insertionSortCompareCount(int* a, int n, long long& count_compare);

// Selection sort algorithm
void selectionSortCompareCount(int* a, int n, long long& count_compare);

// Bubble sort algorithm
void BubbleSortCompareCount(int* a, int n, long long& count_compare);

// Shaker (Cocktail) Sort algorithm
void shakerSortCompareCount(int* a, int n, long long& count_compare);

// Shell Sort algorithm
void shellSortCompareCount(int *a, int n, long long& count_compare);

// Heap sort algorithm
void heapify(int* a, int n, int i, long long& count_compare);				// sub function for heap sort algorithm
void heapSortCompareCount(int* a, int n, long long& count_compare);

// Merge sort algorithm
void merge(int *a, int l, int m, int r, long long& count_compare);		// sub function for merge sort algorithm
void mergeSortCompareCount(int *a, int l, int r, long long& count_compare);

// Quick sort algorithm
int medianOfThree(int* a, int l, int r, long long& count_compare);
int partition(int* a, int low, int high, long long& count_compare);		// sub function for quick sort algorithm
void quickSortCompareCount(int* a, int low, int high, long long& count_compare);

// Counting Sort algorithm
void countingSortCompareCount(int *a, int n, long long& count_compare);

// Radix sort algorithm
void countSort(int* a, int n, int exp, long long& count_compare);			// sub function for radix sort
int FindMax(int *a, int n, long long& count_compare);
void radixsortCompareCount(int* a, int n, long long& count_compare);

// Flash sort algorithm 
int FindMin(int *a, int n, long long& count_compare);
void FlashSortCompareCount(int *a, int n, long long& count_compare);