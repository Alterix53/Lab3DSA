#include "Command.h"

// function to call the sorting algorithm and get the comparison number and/or run time
void RunSorting(int *arr, int arraySize, char algorithmName[], char outputParameters[], double& runtime, long long& compare) {
	string runMode(outputParameters);
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
			FlashSortCompareCount(arr, arraySize, compare);
			break;
		}
		default:
			break;
		}
	}
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
			start = clock();
			FlashSort(arr, arraySize);
			end = clock();
			break;
		}
		default:
			break;
		}
		runtime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
	}
	
}

// Function that runs the sorting algorithm on a specific array order
// This function is used in the third command
void RunSpecificArrayOrderType(int arrSize, int arrOrder, char algorithmName[], char outputParameters[], string fileName) {

	// initialize needed variables	
	int* arr = new int[arrSize];
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

	// delete the array
	delete[] arr;
}

// function that runs the first command type
void RunCommandTypeOne(char algorithmName[], char fileName[], char outputParameters[]) {

	// read the array from the file
	int arrSize;
	int* arr = ReadArrayFromFile(arrSize, fileName);

	// print the basic info base on the command
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm name: " << GetAlgorithmName(algorithmName) << endl;
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

// function that runs the second command type
void RunCommandTypeTwo(char algorithmName[], char inputSize[], char inputOrder[], char outputParameters[]) {

	// create an array based on user's command
	int arrSize = convertStringToNum(inputSize);
	int arrayOrder = ArrayOrderType(inputOrder);
	int* arr = new int[arrSize];
	GenerateData(arr, arrSize, arrayOrder);
	
	// write the array into file
	WriteArrayToFile(arr, arrSize, "input.txt");

	// print the basic info base on the command
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm name: " << GetAlgorithmName(algorithmName) << endl;
	cout << "Input size: " << arrSize << endl;
	cout << "Input order: " << GetOutputParameter(inputOrder) << endl;
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

// function that runs the third command type
void RunCommandTypeThree(char algorithmName[], char inputSize[], char outputParameters[]) {
	
	// initialized needed 
	int arrSize = convertStringToNum(inputSize);
	
	// print basic information
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << GetAlgorithmName(algorithmName) << endl;
	cout << "Input size: " << arrSize << endl << endl;

	// run each array order: (randomize, sorted, nearly sorted, reverse)
	// Randomize:
	cout << "Input Order: Randomize" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arrSize, 0, algorithmName, outputParameters, "input_1.txt");
	cout << endl;

	// Nearly sorted
	cout << "Input Order: Nearly Sorted" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arrSize, 3, algorithmName, outputParameters, "input_2.txt");
	cout << endl;

	// Sorted
	cout << "Input Order: Sorted" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arrSize, 1, algorithmName, outputParameters, "input_3.txt");
	cout << endl;

	// Reverse
	cout << "Input Order: Reversed" << endl;
	cout << "-----------------------------" << endl;
	RunSpecificArrayOrderType(arrSize, 2, algorithmName, outputParameters, "input_4.txt");
	cout << endl;

}

// function that runs the fourth command type
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
	cout << "Algorithm: " << GetAlgorithmName(algorithmName1) << " | " << GetAlgorithmName(algorithmName2) << endl;
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

// function that runs the fifth command type
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
	
	// write the generated input 
	WriteArrayToFile(arr, arrSize, "input.txt");

	// copy the data generated in first array to second array
	int* arr2 = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr2[i] = arr[i];
	}


	// print the basic info based on the command
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << GetAlgorithmName(algorithmName1) << " | " << GetAlgorithmName(algorithmName2) << endl;
	cout << "input size: " << arrSize << endl;
	cout << "input order: " << GetOutputParameter(inputOrder) << endl;
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