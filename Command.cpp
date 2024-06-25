#include "Command.h"
#include "CheckParameter.h"
#include "SortAndCountRuntime.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;
void runSorting(int a[], int n, char algo[], char mode[], double &runtime, long long comparision) {
	string runMode(mode);
	if (runMode == "-time" || runMode == "-both") {
		clock_t start, end;
		// call the function base on the input type
		switch (AlgorithmType(algo)) {
		case 0: {
			start = clock();
			selectionSort(a, n);
			end = clock();
			break;
		}
		case 1: {
			start = clock();
			insertionSort(a, n);
			end = clock();
			break;
		}
		case 2: {
			start = clock();
			bubbleSort(a, n);
			end = clock();
			break;
		}
		case 3: {
			start = clock();
			shakerSort(a, n);
			end = clock();
			break;
		}
		case 4: {
			start = clock();
			shellSort(a, n);
			end = clock();
			break;
		}
		case 5: {
			start = clock();
			heapSort(a, n);
			end = clock();
			break;
		}
		case 6: {
			start = clock();
			mergeSort(a, 0, n - 1);
			end = clock();
			break;
		}
		case 7: {
			start = clock();
			quickSort(a, 0, n - 1);
			end = clock();
			break;
		}
		case 8: {
			start = clock();
			countingSort(a, n);
			end = clock();
			break;
		}
		case 9: {
			start = clock();
			radixsort(a, n);
			end = clock();
			break;
		}
		case 10: {
			break;
		}
		default:
			break;
		}
		runtime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
	}
	if (runMode == "-comp" || runMode == "-both") {
		return;
	}
}

// function that runs the first command type
void runCommandTypeOne(int argc, char *argv[]) {

	string fileName(argv[3]);
	ifstream ifs;
	
	// read the array from the file
	ifs.open(fileName);
	if (!ifs) {
		cout << "Can not open the file named " << fileName;
		return;
	}
	int n;
	ifs >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		ifs >> a[i];
	}
	ifs.close();

	
	double runtime;
	

	cout << runtime;

	// open the file to write the sorted array
	ofstream ofs;
	ofs.open("output.txt");
	if (!ofs) {
		cout << "Can not open the file named output.txt!";
		return;
	}
	ofs << n << "\n";					// number of elements
	for (int i = 0; i < n; i++) {
		ofs << a[i] << " ";				// write each elements
	}
	ofs.close();
	delete[] a;
}

void RunCommandTypeTwo(int argc, char* argv[]) {

}