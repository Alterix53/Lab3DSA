#pragma once

// the Sorting algorithm here is similar to the Sorting algorithm 
// the algorithm here aslo count the number of comparison while running the function

void swap(int& a, int& b);
int getMax(int a[], int n, long long& count_compare);
void BubbleSortCompareCount(int a[], int n, long long& count_compare);
void countSort(int a[], int n, int exp, long long& count_compare);
void radixsortCompareCount(int a[], int n, long long& count_compare);
void heapify(int a[], int N, int i, long long& count_compare);
void HeapSortCompareCount(int a[], int N, long long& count_compare);
void mergeSortCompareCount(int a[], int l, int r, long long& count_compare);
void selectionSortCompareCount(int a[], int n, long long& count_compare);
void heapify(int a[], int n, int i, long long& count_compare);
void heapSortCompareCount(int a[], int n, long long& count_compare);
int partition(int a[], int low, int high, long long& count_compare);
void quickSortCompareCount(int a[], int low, int high, long long& count_compare);	// Quick Sort 

void insertionSortCompareCount(int a[], int n, long long& compareCount);					// Insertion Sort algorithm with comparison count

void shakerSortCompareCount(int a[], int n, long long& compareCount);						// Shaker (Cocktail) Sort algorithm with comparison count

void shellSortCompareCount(int a[], int n, long long& compareCount);						// Shell Sort algorithm with comparison count

void countingSortCompareCount(int a[], int n, long long& compareCount);					// Counting Sort algorithm with comparison count