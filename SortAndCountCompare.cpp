#include "SortAndCountCompare.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>

using namespace std;
// https://www.geeksforgeeks.org/bubble-sort-in-cpp/
// https://www.geeksforgeeks.org/radix-sort/
// https://www.geeksforgeeks.org/heap-sort/

void BubbleSortCompareCount(int *a, int n, long long& count_compare)
{
    int i, j;
    count_compare = 0; // Reset biến đếm
    for (i = 0; (++count_compare && i < n - 1); i++) {
        for (j = 0; (++count_compare && j < n - i - 1); j++) {
            if ((++count_compare && a[j] > a[j + 1]))
                swap(a[j], a[j + 1]);
        }
    }
}

int FindMax(int *a, int n, long long& count_compare)
{
    int mx = a[0];
    for (int i = 1; (++count_compare && i < n); i++)
        if (++count_compare && a[i] > mx)
            mx = a[i];
    return mx;
}

int FindMin(int* a, int n, long long& count_compare) {
    int minVal = a[0];
    for (int i = 1; (++count_compare && i < n); i++)
        if (++count_compare && a[i] < minVal)
            minVal = a[i];
    return  minVal;
}

void countSort(int *a, int n, int exp, long long& count_compare)
{
    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; ++count_compare && i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; ++count_compare && i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; ++count_compare && i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; ++count_compare && i < n; i++)
        a[i] = output[i];
    delete[] output;
}


void radixsortCompareCount(int *a, int n, long long& count_compare)
{
    count_compare = 0; // Reset biến đếm
    int m = FindMax(a, n, count_compare);

    for (int exp = 1; ++count_compare && m / exp > 0; exp *= 10)
        countSort(a, n, exp, count_compare);
}

void heapify(int *a, int n, int i, long long& count_compare) {
    // Initialize largest as root
    int largest = i;
    // left = 2*i + 1
    int l = 2 * i + 1;
    // right = 2*i + 2
    int r = 2 * i + 2;
    // If left child is larger than root
    if (++count_compare && l < n && a[l] > a[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (++count_compare && r < n && a[r] > a[largest]) {
        largest = r;
    }
    // If largest is not root
    if (++count_compare && largest != i) {
        swap(a[i], a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest, count_compare);
    }
}


void HeapSortCompareCount(int *a, int N, long long& count_compare)
{
    count_compare = 0; // Reset biến đếm
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i, count_compare);

    for (int i = N - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, count_compare);
    }
}

// --------------- TAN THANG ---------------------

long long count_compare;

void swap(long long& a, long long& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSortCompareCount(int *a, int n, long long& count_compare) {
    // Initialize counters for comparisons
    count_compare = 0;

    // Traverse the aay
    for (int i = 0; i < n - 1; ++i) {
        // Set the initial minimum index to the current position
        int min_idx = i;
        // Traverse the remaining unsorted part of the aay
        for (int j = i + 1; j < n; ++j) {
            count_compare++; // Count each comparison in the inner loop

            // Update min_idx if a smaller element is found
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

void merge(int *a, int l, int m, int r, long long& count_compare)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; ++count_compare && i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; ++count_compare && j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while ((++count_compare && i < n1) && (++count_compare && j < n2)) {
        if (++count_compare && L[i] <= R[j]) {
            a[k] = L[i++];
        }
        else {
            a[k] = R[j++];
        }
        k++;
    }

    while (++count_compare && i < n1) {
        a[k++] = L[i++];
    }

    while (++count_compare && j < n2) {
        a[k++] = R[j++];
    }

    delete[]L;
    delete[]R;
}

void mergeSortCompareCount(int *a, int l, int r, long long& count_compare)
{
    if (++count_compare && l < r) {
        int m = l + (r - l) / 2;
        mergeSortCompareCount(a, l, m, count_compare);
        mergeSortCompareCount(a, m + 1, r, count_compare);
        merge(a, l, m, r, count_compare);
    }
}
void heapSortCompareCount(int *a, int n, long long& count_compare) {
    count_compare = 0;
    // Build heap (reaange aay)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i, count_compare);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(a[0], a[i]);
        // Call max heapify on the reduced heap
        heapify(a, i, 0, count_compare);
    }
}

// Find the median element in the aay
int medianOfThree(int* a, int l, int r, long long& count_compare) {
    int mid = l + (r - l) / 2;
    if (++count_compare && a[l] > a[mid]) swap(a[l], a[mid]);
    if (++count_compare && a[l] > a[r]) swap(a[l], a[r]);
    if (++count_compare && a[mid] > a[r]) swap(a[mid], a[r]);
    return mid;
}

// Function to partition the aay and return the pivot index after partitioning
int partition(int* a, int l, int r, long long& count_compare) {
    int pivotIndex = medianOfThree(a, l, r, count_compare);
    int pivot = a[pivotIndex];
    swap(a[pivotIndex], a[r]); // Move the pivot to the end for ease of operation
    int i = l - 1;

    for (int j = l; ++count_compare && j < r; ++j) {
        if (++count_compare && a[j] < pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]); // Return the pivot to the correct position
    return i + 1;
}

// Function quick sort
void quickSortCompareCount(int* a, int l, int r, long long& count_compare) {
    if (++count_compare && l < r) {
        int pi = partition(a, l, r, count_compare);
        quickSortCompareCount(a, l, pi - 1, count_compare);
        quickSortCompareCount(a, pi + 1, r, count_compare);
    }
}
// Insertion Sort algorithm with comparison count
void insertionSortCompareCount(int *a, int n, long long& compareCount)
{
    compareCount = 0;  // Initialize comparison count
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && (++compareCount && a[j] > key)) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Shaker (Cocktail) Sort algorithm with comparison count
void shakerSortCompareCount(int *a, int n, long long& compareCount)
{
    compareCount = 0;  // Initialize comparison count
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {  // Forward pass
            if (++compareCount && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;  // Set swapped flag
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {  // Backward pass
            if (++compareCount && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;  // Set swapped flag
            }
        }
        ++start;  // Move start pointer
    
    }
}

// Shell Sort algorithm with comparison count
void shellSortCompareCount(int *a, int n, long long& compareCount)
{
    compareCount = 0;  // Initialize comparison count
    for (int gap = n / 2; gap > 0; gap /= 2) {  // Reduce gap size until it's 1
        for (int i = gap; i < n; i += 1) {  // Perform insertion sort for current gap
            int temp = a[i];  // Store current element in temp
            int j;
            for (j = i; j >= gap && (++compareCount && a[j - gap] > temp); j -= gap) {
                a[j] = a[j - gap];  // Shift elements right
            }
            a[j] = temp;  // Place temp in correct position
        }
    }
}

// Counting Sort algorithm with comparison count
void countingSortCompareCount(int *a, int n, long long& compareCount) {
    compareCount = 0;  // Initialize comparison count

    if (n <= 1) return;  // Base case: already sorted or single element

    int maxVal = a[0], minVal = a[0];
    for (int i = 1; i < n; ++i) {  // Find min and max values in array
        if (++compareCount && a[i] > maxVal) maxVal = a[i];
        if (++compareCount && a[i] < minVal) minVal = a[i];
    }

    int range = maxVal - minVal + 1;
    int* count = new int[range]();  // Initialize count array with zeros

    for (int i = 0; i < n; ++i) {  // Count occurrences of each element
        count[a[i] - minVal]++;  // Increment count for current element
    }

    for (int i = 1; i < range; ++i) {  // Modify count array to reflect positions in output array
        count[i] += count[i - 1];  // Cumulative sum of counts
    }

    int* output = new int[n];

    for (int i = n - 1; i >= 0; --i) {
        output[count[a[i] - minVal] - 1] = a[i];  // Place elements in output array
        count[a[i] - minVal]--;  // Decrement count for current element
    }

    for (int i = 0; i < n; ++i) {
        a[i] = output[i];  // Copy sorted elements back to original array
    }

    delete[] count;
    delete[] output;
}
void FlashSortCompareCount(int* a, int n, long long &count_compare) {
    if (++count_compare && n <= 1) return;

    // Bước 1: create classes
    int m = int(0.45 * n); // number of classes is 0.45*(number of elements in aay)
    int* L = new int[m]();

    int minVal = FindMin(a, n, count_compare);
    int maxVal = FindMax(a, n, count_compare);

    // return if min = max, means that all element are the same
    if (++count_compare && minVal == maxVal) {
        delete[] L;
        return;
    }

    double c1 = (double)(m - 1) / (maxVal - minVal);

    for (int i = 0; ++count_compare, i < n; i++) {
        int k = int(c1 * (a[i] - minVal));
        L[k]++;
    }

    // build starting classes
    for (int i = 1; ++count_compare, i < m; i++) {
        L[i] += L[i - 1];
    }

    // Put elements into the correct class and sort locall
    int count = 0;
    int i = 0;
    while (++count_compare && count < n) {
        int k = int(c1 * (a[i] - minVal));
        while (++count_compare && i >= L[k]) {
            k = int(c1 * (a[++i] - minVal));
        }
        int temp = a[i];
        while (++count_compare && i != L[k]) {
            k = int(c1 * (temp - minVal));
            int pos = --L[k];
            swap(temp, a[pos]);
            count++;
        }
    }

    // use insertion sort for sorting each class
    for (int i = 1; ++count_compare, i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while ((++count_compare && j >= 0) && (++count_compare && a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    // delete the aay
    delete[] L;
}