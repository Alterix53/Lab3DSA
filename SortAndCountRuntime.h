#pragma once

// https://www.geeksforgeeks.org/bubble-sort-in-cpp/
// https://www.geeksforgeeks.org/radix-sort/


// ------------------------ PHAM ANH ----------------------
void bubbleSort(int a[], int n);

int getMax(int a[], int n);
// A function to do counting sort of a[]
// according to the digit
// represented by exp.
void countSort(int a[], int n, int exp);
// The main function to that sorts a[]
// of size n using Radix Sort
void radixsort(int a[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
// --------------------- TAN THANG ----------------------
//https://www.geeksforgeeks.org/quick-sort/
//https://www.geeksforgeeks.org/cpp-program-for-selection-sort/
//https://www.geeksforgeeks.org/heap-sort/

void swap(int& a, int& b);
void selectionSort(int a[], int n);

void heapify(int a[], int n, int i);

void heapSort(int a[], int n);

int partition(int a[], int low, int high);

void quickSort(int a[], int low, int high);

// --------------------------- LE KHOI ------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Insertion Sort algorithm
void insertionSort(int a[], int n);

// Shaker (Cocktail) Sort algorithm
void shakerSort(int a[], int n);
// Shell Sort algorithm
void shellSort(int arr[], int n);
// Counting Sort algorithm
void countingSort(int arr[], int n);

void printArray(int arr[], int n);
