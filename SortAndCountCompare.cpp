#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
// https://www.geeksforgeeks.org/bubble-sort-in-cpp/
// https://www.geeksforgeeks.org/radix-sort/
// https://www.geeksforgeeks.org/heap-sort/

void BubbleSortCompareCount(int a[], int n, long long& count_compare)
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

int getMax(int a[], int n, long long& count_compare)
{
    int mx = a[0];
    for (int i = 1; (++count_compare && i < n); i++)
        if (++count_compare && a[i] > mx)
            mx = a[i];
    return mx;
}

void countSort(int a[], int n, int exp, long long& count_compare)
{
    int *output = new int[n];
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

void radixsortCompareCount(int a[], int n, long long& count_compare)
{
    count_compare = 0; // Reset biến đếm
    int m = getMax(a, n, count_compare);

    for (int exp = 1; ++count_compare && m / exp > 0; exp *= 10)
        countSort(a, n, exp, count_compare);
}

void heapify(int a[], int N, int i, long long& count_compare)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((++count_compare && l < N) && (++count_compare && a[l] > a[largest]))
        largest = l;

    if ((++count_compare && r < N) && (++count_compare && a[r] > a[largest]))
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, N, largest, count_compare);
    }
}

void HeapSortCompareCount(int a[], int N, long long& count_compare)
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

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int a[], int n, long long& count_compare) {
    // Initialize counters for comparisons
    count_compare = 0;

    // Traverse the array
    for (int i = 0; i < n - 1; ++i) {
        // Set the initial minimum index to the current position
        int min_idx = i;
        // Traverse the remaining unsorted part of the array
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

void heapify(int a[], int n, int i, long long& count_compare) {
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

void heapSort(int a[], int n, long long& count_compare) {
    count_compare = 0;
    // Build heap (rearrange array)
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

int partition(int a[], int low, int high, long long& count_compare) {
    // Choose the pivot
    int pivot = a[high];
    // Index of smaller element and indicate the right position of pivot found so far
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        count_compare++; // for the comparison in the if statement
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

void quickSort(int a[], int low, int high, long long& count_compare) {
    // When low is less than high
    if (++count_compare && low < high) {
        // pi is the partition return index of pivot
        int pi = partition(a, low, high, count_compare);
        // Recursion Call
        // Smaller element than pivot goes left and higher element goes right
        quickSort(a, low, pi - 1, count_compare);
        quickSort(a, pi + 1, high, count_compare);
    }
}
