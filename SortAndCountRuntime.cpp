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
void bubbleSort(int a[], int n)
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

int getMax(int a[], int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

// A function to do counting sort of a[]
// according to the digit
// represented by exp.
void countSort(int a[], int n, int exp)
{

    // Output array
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

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    // Copy the output array to a[],
    // so that a[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        a[i] = output[i];
    delete[] output;
}

// The main function to that sorts a[]
// of size n using Radix Sort
void radixsort(int a[], int n)
{

    // Find the maximum number to
    // know number of digits
    int m = getMax(a, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo mảng tạm
    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Trộn mảng tạm vào mảng chính
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Tìm điểm chính giữa
        int m = l + (r - l) / 2;

        // Gọi đệ quy sắp xếp hai nửa
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Trộn hai nửa đã sắp xếp
        merge(arr, l, m, r);
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

void selectionSort(int a[], int n) {
    // Traverse the array
    for (int i = 0; i < n - 1; ++i) {
        // Set the initial minimum index to the current position
        int min_idx = i;
        // Traverse the remaining unsorted part of the array
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

void heapify(int a[], int n, int i) {
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

void heapSort(int a[], int n) {
    // Build heap (rearrange array)
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

int partition(int a[], int low, int high) {
    // Choose the pivot
    int pivot = a[high];
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

void quickSort(int a[], int low, int high) {
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
void insertionSort(int a[], int n)
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
void shakerSort(int a[], int n)
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
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2) {  // Reduce gap size until it's 1
        for (int i = gap; i < n; i += 1) {  // Perform insertion sort for current gap
            int temp = arr[i];  // Store current element in temp
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];  // Shift elements right
            }
            arr[j] = temp;  // Place temp in correct position
        }
    }
}

// Counting Sort algorithm
void countingSort(int arr[], int n) {
    if (n <= 1) return;  // Base case: already sorted or single element

    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < n; ++i) {  // Find min and max values in array
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    int range = maxVal - minVal + 1;
    int* count = new int[range]();  // Initialize count array with zeros

    for (int i = 0; i < n; ++i) {  // Count occurrences of each element
        count[arr[i] - minVal]++;  // Increment count for current element
    }

    for (int i = 1; i < range; ++i) {  // Modify count array to reflect positions in output array
        count[i] += count[i - 1];  // Cumulative sum of counts
    }

    int* output = new int[n];

    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];  // Place elements in output array
        count[arr[i] - minVal]--;  // Decrement count for current element
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];  // Copy sorted elements back to original array
    }

    delete[] count;
    delete[] output;
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//int main(int argc, char* argv[]) {
//    if (argc != 3) {
//        cout << "Usage: " << argv[0] << " <sort_type> <array_size>" << endl;
//        return 1;
//    }
//
//    string sortType = argv[1];
//    int n = atoi(argv[2]);
//
//    int* arr = new int[n];
//    GenerateRandomData(arr, n);
//
//    double start = clock();
//    if (sortType == "insertion") {
//        insertionSort(arr, n);
//    }
//    else if (sortType == "shaker") {
//        shakerSort(arr, n);
//    }
//    else if (sortType == "shell") {
//        shellSort(arr, n);
//    }
//    else if (sortType == "counting") {
//        countingSort(arr, n);
//    }
//    else {
//        cout << "Unknown sort type: " << sortType << endl;
//        delete[] arr;
//        return 1;
//    }
//    double end = clock();
//    double run_time = (end - start) / CLOCKS_PER_SEC;
//
//    cout << "Sorted array: ";
//    printArray(arr, n);
//
//    cout << "Comparison count: " << compareCount << endl;
//    cout << "Runtime: " << run_time << " seconds" << endl;
//
//    delete[] arr;
//    return 0;
//}

//int main() {
//    int n;
//    cout << "Please choose the number of elements: ";
//    cin >> n;
//
//    int* arr = new int[n];
//
//    cout << "Please choose the type of array to create:" << endl;
//    cout << "1. GenerateSortedData" << endl;
//    cout << "2. GenerateNearlySortedData" << endl;
//    cout << "3. GenerateReverseData" << endl;
//    cout << "4. GenerateRandomData" << endl;
//
//    int genType;
//    cin >> genType;
//
//    switch (genType) {
//    case 1:
//        GenerateSortedData(arr, n);
//        break;
//    case 2:
//        GenerateNearlySortedData(arr, n);
//        break;
//    case 3:
//        GenerateReverseData(arr, n);
//        break;
//    case 4:
//        GenerateRandomData(arr, n);
//        break;
//    default:
//        cout << "Invalid choice" << endl;
//        delete[] arr;
//        return 0;
//    }
//
//    cout << "Please choose the type of sort algorithm:" << endl;
//    cout << "1. Shaker Sort" << endl;
//    cout << "2. Shell Sort" << endl;
//    cout << "3. Counting Sort" << endl;
//
//    int sortType;
//    cin >> sortType;
//
//    clock_t start, end;
//    double runtime;
//
//    cout << "Array before sorting:";
//    printArray(arr, n);
//    cout << endl;
//
//    switch (sortType) {
//    case 1:
//        start = clock();
//        shakerSort(arr, n);
//        end = clock();
//        break;
//    case 2:
//        start = clock();
//        shellSort(arr, n);
//        end = clock();
//        break;
//    case 3:
//        start = clock();
//        countingSort(arr, n);
//        end = clock();
//        break;
//    default:
//        cout << "Unknown sort type" << endl;
//        delete[] arr;
//        return 0;
//    }
//
//    runtime = double(end - start) / CLOCKS_PER_SEC;
//
//    cout << "Sorted array: ";
//    printArray(arr, n);
//
//    cout << "Runtime: " << runtime << " seconds" << endl;
//
//    delete[] arr;
//    return 0;
//}
