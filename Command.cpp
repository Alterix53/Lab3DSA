#include "Command.h"
#include "CheckParameter.h"
#include "SortAndCountRuntime.h"
#include "SortAndCountCompare.h"
#include "DataGenerator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;

string ConverString(char inputOrder[]) {
	string output(inputOrder);
	if (output == "-rand")
		return "Randomize";
	if (output == "-nsorted")
		return "Nearly sorted";
	if (output == "-rev")
		return "Reverse";
	if (output == "sorted")
		return "Sorted";
	return "";
}

void WriteArrayToFile(int arr[], int arrSize, string fileName) {
	ofstream ofs;
	ofs.open(fileName); 
	if (!ofs) {
		cout << "Can not open file name " << fileName << "!";
		return;
	}
	ofs << arrSize << endl;
	for (int i = 0; i < arrSize; i++) {
		ofs << arr[i] << " ";
	}
	ofs.close();
}

int * ReadArrayFromFile(int &arrSize, string fileName) {
	ifstream ifs;
	ifs.open(fileName);
	if (!ifs) {
		cout << "Can not open the file named " << fileName << "!";
		exit(EXIT_FAILURE);
	}
	ifs >> arrSize;
	int* arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		ifs >> arr[i];
	}
	ifs.close();
	return arr;
}
void RunSorting(int arr[], int arraySize, char algorithmName[], char outputParameters[], double& runtime, long long& compare) {
	string runMode(outputParameters);
	if (runMode == "-time" || runMode == "-both") {
		clock_t start, end;
		// call the function base on the input type
		switch (AlgorithmType(algorithmName)) {
		case 0: {
			start = clock();
			selectionSort(arr, arraySize);
			end = clock();
			break;
		}
		case 1: {
			start = clock();
			insertionSort(arr, arraySize);
			end = clock();
			break;
		}
		case 2: {
			start = clock();
			bubbleSort(arr, arraySize);
			end = clock();
			break;
		}
		case 3: {
			start = clock();
			shakerSort(arr, arraySize);
			end = clock();
			break;
		}
		case 4: {
			start = clock();
			shellSort(arr, arraySize);
			end = clock();
			break;
		}
		case 5: {
			start = clock();
			heapSort(arr, arraySize);
			end = clock();
			break;
		}
		case 6: {
			start = clock();
			mergeSort(arr, 0, arraySize - 1);
			end = clock();
			break;
		}
		case 7: {
			start = clock();
			quickSort(arr, 0, arraySize - 1);
			end = clock();
			break;
		}
		case 8: {
			start = clock();
			countingSort(arr, arraySize);
			end = clock();
			break;
		}
		case 9: {
			start = clock();
			radixsort(arr, arraySize);
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
		switch (AlgorithmType(algorithmName)) {
		case 0: {
			selectionSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 1: {
			insertionSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 2: {
			BubbleSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 3: {
			shakerSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 4: {
			shellSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 5: {
			heapSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 6: {
			mergeSortCompareCount(arr, 0, arraySize - 1, compare);
			break;
		}
		case 7: {
			quickSortCompareCount(arr, 0, arraySize - 1, compare);
			break;
		}
		case 8: {
			countingSortCompareCount(arr, arraySize, compare);
			break;
		}
		case 9: {
			radixsortCompareCount(arr, arraySize, compare);
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

void PrintResultAlgorithmMode(char outputParameters[], double runtime, long long compare) {
	if (strcmp(outputParameters, "-time") == 0 || strcmp(outputParameters, "-both") == 0)
		cout << "Running time: " << runtime << " miliseconds." << endl;
	if (strcmp(outputParameters, "-comp") == 0 || strcmp(outputParameters, "-both") == 0)
		cout << "Comparisions: " << compare << " comparisions." << endl;
}

void PrintResultCompareMode(double runtime1, double runtime2, long long compare1, long long compare2) {
	cout << "Running time: " << runtime1 << " | " << runtime2 << " miliseconds." << endl;
	cout << "Comparisions: " << compare1 << " | " << compare2 << " comparisions." << endl;
}

// function that runs the first command type
// NOTES: argv[0]: execution file name; argv[1]: -a; argv[2]: algorithm name; argv[3]: input file; argv[4]: output parameters
void RunCommandTypeOne(char algorithmName[], char fileName[], char outputParameters[]) {

	// read the array from the file
	int arrSize;
	int* arr = ReadArrayFromFile(arrSize, fileName);

	// print the basic info base on the command
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm name: " << algorithmName << endl;
	cout << "Input file: " << fileName << endl;
	cout << "input size: " << arrSize << endl;
	cout << "---------------------------------" << endl;

	// run the correctspoding sorting algorithm
	long long compare = 0;
	double runtime = 0;
	RunSorting(arr, arrSize, algorithmName, outputParameters, runtime, compare);

	// print the result
	PrintResultAlgorithmMode(outputParameters, runtime, compare);

	// open the file to write the sorted array
	WriteArrayToFile(arr, arrSize, "output.txt");

	// delete the array
	delete[] arr;
}

void RunCommandTypeTwo(char algorithmName[], char inputSize[], char inputOrder[], char outputParameters[]) {

	// create an array based on user's command
	int arrSize = convertStringToNum(inputSize);
	int arrayOrder = ArrayOrderType(inputOrder);
	int* arr = new int[arrSize];
	GenerateData(arr, arrSize, arrayOrder);
	
	// write the array into file
	WriteArrayToFile(arr, arrSize, "input.txt");

	// print the basic info base on the command
	cout << "Algorithm name: " << algorithmName << endl;
	cout << "Input size: " << arrSize << endl;
	cout << "Input order" << ConverString(inputOrder);
	cout << "---------------------------------" << endl;

	// run the correctspoding sorting algorithm
	long long compare = 0;
	double runtime = 0;
	RunSorting(arr, arrSize, algorithmName, outputParameters, runtime, compare);

	// print the result
	PrintResultAlgorithmMode(outputParameters, runtime, compare);

	// open the file to write the sorted array
	WriteArrayToFile(arr, arrSize, "output.txt");

	// delete the array 
	delete[] arr;
}

void RunSpecificArrayOrderType(int arr[], int arrSize, int arrOrder, char algorithmName[], char outputParameters[], string fileName) {

	// initialize needed variables
	double runtime = 0;
	long long compare = 0;

	// create the array base on order type
	GenerateData(arr, arrSize, arrOrder);

	// write the array into file
	WriteArrayToFile(arr, arrSize, fileName);

	// start sorting 
	RunSorting(arr, arrSize, algorithmName, outputParameters, runtime, compare);

	// print the result
	PrintResultAlgorithmMode(outputParameters, runtime, compare);

}

void RunCommandTypeThree(char algorithmName[], char inputSize[], char outputParameters[]) {
	
	// initialized needed 
	int arrSize = convertStringToNum(inputSize);
	int* arr = new int[arrSize];

	// print basic information
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input size: " << arrSize << endl << endl;

	// run each array order: (randomize, sorted, nearly sorted, reverse)
	// Randomize:
	cout << "Input Order: Randomize" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arr, arrSize, 0, algorithmName, outputParameters, "input_1.txt");

	// Nearly sorted
	cout << "Input Order: Nearly Sorted" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arr, arrSize, 3, algorithmName, outputParameters, "input_2.txt");

	// Sorted
	cout << "Input Order: Sorted" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arr, arrSize, 1, algorithmName, outputParameters, "input_3.txt");

	// Reverse
	cout << "Input Order: Reversed" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arr, arrSize, 2, algorithmName, outputParameters, "input_4.txt");

	// delete the array
	delete[] arr;
}

void RunCommandTypeFour(char algorithmName1[], char algorithmName2[], char fileName[]) {

	// initialize needed variables
	double runtime1 = 0, runtime2 = 0;
	long long compare1 = 0, compare2 = 0;
	char mode[] = "-both";						// compare both running times and numbers of comparisions

	// read the array from the file
	int arrSize = 0;
	int* arr = ReadArrayFromFile(arrSize, fileName);

	// print the basic info base on the command
	// this comes after the first reading file function, make sure that the file read is worked correctly
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << endl;
	cout << "Input file: " << fileName << endl;
	cout << "input size: " << arrSize << endl;
	cout << "---------------------------------" << endl;

	// run the first sorting algorithm 
	RunSorting(arr, arrSize, algorithmName1, mode, runtime1, compare1);

	// reset the array by read the file again, then run the second sorting algorithm
	arr = ReadArrayFromFile(arrSize, fileName);
	RunSorting(arr, arrSize, algorithmName2, mode, runtime2, compare2);

	// print the result
	PrintResultCompareMode(runtime1, runtime2, compare1, compare2);

	// delete the array
	delete[] arr;
}

void RunCommandTypeFive(char algorithmName1[], char algorithmName2[], char inputSize[], char inputOrder[]) {
	
	// initialize needed variables
	double runtime1 = 0, runtime2 = 0;
	long long compare1 = 0, compare2 = 0;
	char mode[] = "-both";						// compare both running times and numbers of comparisions

	// create an array based on user's command
	int arrSize = convertStringToNum(inputSize);
	int arrayOrder = ArrayOrderType(inputOrder);
	int* arr = new int[arrSize];
	GenerateData(arr, arrSize, arrayOrder);
	
	// copy the data generated in first array to second array
	int* arr2 = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr2[i] = arr[i];
	}


	// print the basic info based on the command
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << endl;
	cout << "input size: " << arrSize << endl;
	cout << "input order: " << ConverString(inputOrder);
	cout << "---------------------------------" << endl;

	// Run both sorting algorithm
	RunSorting(arr, arrSize, algorithmName1, mode, runtime1, compare1);
	RunSorting(arr2, arrSize, algorithmName2, mode, runtime2, compare2);

	// print the result
	PrintResultCompareMode(runtime1, runtime2, compare1, compare2);

	// delete both arrays
	delete[] arr;
	delete[] arr2;
}