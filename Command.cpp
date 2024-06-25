#include "Command.h"
#include "CheckParameter.h"
#include "SortAndCountRuntime.h"
#include "SortAndCountCompare.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;
void runSorting(int a[], int n, char algo[], char mode[], double& runtime, long long& compare) {
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
		compare = 0;
		switch (AlgorithmType(algo)) {
		case 0: {
			selectionSortCompareCount(a, n, compare);
			break;
		}
		case 1: {
			insertionSortCompareCount(a, n, compare);
			break;
		}
		case 2: {
			BubbleSortCompareCount(a, n, compare);
			break;
		}
		case 3: {
			shakerSortCompareCount(a, n, compare);
			break;
		}
		case 4: {
			shellSortCompareCount(a, n, compare);
			break;
		}
		case 5: {
			heapSortCompareCount(a, n, compare);
			break;
		}
		case 6: {
			mergeSortCompareCount(a, 0, n - 1, compare);
			break;
		}
		case 7: {
			quickSortCompareCount(a, 0, n - 1, compare);
			break;
		}
		case 8: {
			countingSortCompareCount(a, n, compare);
			break;
		}
		case 9: {
			radixsortCompareCount(a, n, compare);
			break;
		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}
}

// function that runs the first command type
// NOTES: argv[0]: execution file name; argv[1]: -a; argv[2]: algorithm name; argv[3]: input file; argv[4]: output parameters
void runCommandTypeOne(int argc, char algorithmName[], char fileName[], char outputParameters[]) {

	// read the array from the file
	ifstream ifs;

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

	// run the correctspoding sorting algorithm
	long long compare = 0;
	double runtime = 0;
	runSorting(a, n, algorithmName, outputParameters, runtime, compare);

	// print the info base on the command;
	cout << "Algorithm name: " << algorithmName << endl;
	cout << "Input file: " << fileName << endl;
	cout << "input size: " << n << endl;
	cout << "---------------------------------" << endl;
	if (strcmp(outputParameters, "-time") == 0 || strcmp(outputParameters, "-both") == 0)
		cout << "Running time: " << runtime << " miliseconds.";
	if (strcmp(outputParameters, "-comp") == 0 || strcmp(outputParameters, "-both") == 0)
		cout << "Comparisions: " << compare << " comparisions." << endl;

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
	return;
}