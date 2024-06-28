#pragma once

// https://www.geeksforgeeks.org/bubble-sort-in-cpp/
// https://www.geeksforgeeks.org/radix-sort/
// https://www.geeksforgeeks.org/quick-sort/
// https://www.geeksforgeeks.org/cpp-program-for-selection-sort/
// https://www.geeksforgeeks.org/heap-sort/


// ----------------- ALL SORTING ALGORITHM -----------------------------
// Insertion Sort algorithm
void insertionSort(int* a, int n);

// Selection sort algorithm
void selectionSort(int* a, int n);

// Bubble sort algorithm
void bubbleSort(int *a, int n);

// Shaker (Cocktail) Sort algorithm
void shakerSort(int *a, int n);

// Shell Sort algorithm
void shellSort(int *a, int n);

// Heap sort algorithm
void heapify(int *a, int n, int i);				// sub function for heap sort algorithm
void heapSort(int *a, int n);

// Merge sort algorithm
void merge(int *a, int l, int m, int r);		// sub function for merge sort algorithm
void mergeSort(int *a, int l, int r);

// Quick sort algorithm
int medianOfThree(int* a, int l, int r);
int partition(int *a, int low, int high);		// sub function for quick sort algorithm
void quickSort(int *a, int low, int high);

// Counting Sort algorithm
void countingSort(int *a, int n);

// Radix sort algorithm
void countSort(int *a, int n, int exp);			// sub function for radix sort
int FindMax(int *a, int n);
void radixsort(int *a, int n);	

// Flash sort algorithm 
int FindMin(int *a, int n);
void FlashSort(int *a, int n);
