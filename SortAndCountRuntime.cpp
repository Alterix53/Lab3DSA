#include<iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "SortAndCountRuntime.h"
using namespace std;
// https://www.geeksforgeeks.org/bubble-sort-in-cpp/
// https://www.geeksforgeeks.org/radix-sort/


// ------------------------ PHAM ANH ----------------------
void bubbleSort(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {

        // Last i elements are already 
        // in place 
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}


int FindMax(int *a, int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    return maxVal;
}

// A function to do counting sort of *a
// according to the digit
// represented by exp.
void countSort(int *a, int n, int exp)
{

    // Output aay
    int* output = new int[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output aay
    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    // Copy the output aay to *a,
    // so that *a now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        a[i] = output[i];
    delete[] output;
}

// The main function to that sorts *a
// of size n using Radix Sort
void radixsort(int *a, int n)
{

    // Find the maximum number to
    // know number of digits
    int m = FindMax(a, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
void merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo mảng tạm
    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    // Trộn mảng tạm vào mảng chính
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int *a, int l, int r) {
    if (l < r) {
        // Tìm điểm chính giữa
        int m = l + (r - l) / 2;

        // Gọi đệ quy sắp xếp hai nửa
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        // Trộn hai nửa đã sắp xếp
        merge(a, l, m, r);
    }
}


// --------------------- TAN THANG ----------------------
#include <iostream>

using namespace std;

//https://www.geeksforgeeks.org/quick-sort/
//https://www.geeksforgeeks.org/cpp-program-for-selection-sort/
//https://www.geeksforgeeks.org/heap-sort/

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *a, int n) {
    // Traverse the aay
    for (int i = 0; i < n - 1; ++i) {
        // Set the initial minimum index to the current position
        int min_idx = i;
        // Traverse the remaining unsorted part of the aay
        for (int j = i + 1; j < n; ++j) {
            // Update min_idx if a smaller element is found
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

void heapify(int *a, int n, int i) {
    // Initialize largest as root
    int largest = i;
    // left = 2*i + 1
    int l = 2 * i + 1;
    // right = 2*i + 2
    int r = 2 * i + 2;
    // If left child is larger than root
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    // If largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n) {
    // Build heap (reaange aay)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(a[0], a[i]);
        // Call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}
int medianOfThree(int* a, int l, int r) {
    int mid = l + (r - l) / 2;
    if (a[l] > a[mid]) swap(a[l], a[mid]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[mid] > a[r]) swap(a[mid], a[r]);
    return mid;
}
int partition(int *a, int low, int high) {
    // Choose the pivot
    int pivot = medianOfThree(a, low, high);
    // Index of smaller element and indicate the right position of pivot found so far
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (a[j] < pivot) {
            // Increment index of smaller element
            i++;
            // Swap a[i] and a[j]
            swap(a[i], a[j]);
        }
    }
    // Swap a[i + 1] and a[high] (or pivot)
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int *a, int low, int high) {
    // When low is less than high
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(a, low, high);
        // Recursion Call
        // Smaller element than pivot goes left and higher element goes right
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// --------------------------- LE KHOI ------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Insertion Sort algorithm
void insertionSort(int *a, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Shaker (Cocktail) Sort algorithm
void shakerSort(int *a, int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {  // Forward pass
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;  // Set swapped flag
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {  // Backward pass
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;  // Set swapped flag
            }
        }
        ++start;  // Move start pointer
    }
}

// Shell Sort algorithm
void shellSort(int *a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2) {  // Reduce gap size until it's 1
        for (int i = gap; i < n; i += 1) {  // Perform insertion sort for current gap
            int temp = a[i];  // Store current element in temp
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];  // Shift elements right
            }
            a[j] = temp;  // Place temp in correct position
        }
    }
}

// Counting Sort algorithm
void countingSort(int *a, int n) {
    if (n <= 1) return;  // Base case: already sorted or single element

    int maxVal = a[0], minVal = a[0];
    for (int i = 1; i < n; ++i) {  // Find min and max values in aay
        if (a[i] > maxVal) maxVal = a[i];
        if (a[i] < minVal) minVal = a[i];
    }

    int range = maxVal - minVal + 1;
    int* count = new int[range]();  // Initialize count aay with zeros

    for (int i = 0; i < n; ++i) {  // Count occurrences of each element
        count[a[i] - minVal]++;  // Increment count for current element
    }

    for (int i = 1; i < range; ++i) {  // Modify count aay to reflect positions in output aay
        count[i] += count[i - 1];  // Cumulative sum of counts
    }

    int* output = new int[n];

    for (int i = n - 1; i >= 0; --i) {
        output[count[a[i] - minVal] - 1] = a[i];  // Place elements in output aay
        count[a[i] - minVal]--;  // Decrement count for current element
    }

    for (int i = 0; i < n; ++i) {
        a[i] = output[i];  // Copy sorted elements back to original aay
    }

    delete[] count;
    delete[] output;
}


int FindMin(int *a, int n) {
    int minVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i];
        }
    }
    return minVal;
}

void FlashSort(int *a, int n) {
    if (n <= 1) return;

    // Bước 1: create classes
    int m = int(0.45 * n); // number of classes is 0.45*(number of elements in aay)
    int* L = new int[m](); 

    int minVal = FindMin(a, n);
    int maxVal = FindMax(a, n);

    // return if min = max, means that all element are the same
    if (minVal == maxVal) {
        delete[] L;
        return; 
    }

    double c1 = (double)(m - 1) / (maxVal - minVal);

    for (int i = 0; i < n; i++) {
        int k = int(c1 * (a[i] - minVal));
        L[k]++;
    }

    // build starting classes
    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }

    // Put elements into the correct class and sort locall
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = int(c1 * (a[i] - minVal));
        while (i >= L[k]) {
            k = int(c1 * (a[++i] - minVal));
        }
        int temp = a[i];
        while (i != L[k]) {
            k = int(c1 * (temp - minVal));
            int pos = --L[k];
            swap(temp, a[pos]);
            count++;
        }
    }

    // use insertion sort for sorting each class
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    // delete the aay
    delete[] L; 
}