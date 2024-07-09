#include "utility.h"
#include "CheckParameter.h"

void WriteArrayToFile(int* arr, int arrSize, string fileName) {
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

int* ReadArrayFromFile(int& arrSize, string fileName) {
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

int AlgorithmType(char algoName[]) {
	string name(algoName);
	if (name == "selection-sort")
		return 0;
	if (name == "insertion-sort")
		return 1;
	if (name == "bubble-sort")
		return 2;
	if (name == "shaker-sort")
		return 3;
	if (name == "shell-sort")
		return 4;
	if (name == "heap-sort")
		return 5;
	if (name == "merge-sort")
		return 6;
	if (name == "quick-sort")
		return 7;
	if (name == "counting-sort")
		return 8;
	if (name == "radix-sort")
		return 9;
	if (name == "flash-sort")
		return 10;
	return -1;
}

int OutputType(char outputType[]) {
	if (!isString(outputType))
		return -1;
	string output(outputType);
	if (output == "-time")
		return 0;
	if (output == "-comp")
		return 1;
	if (output == "-both")
		return 2;
	return -1;
}

int ArrayOrderType(char inputOrder[]) {
	if (!isString(inputOrder))
		return -1;
	string Order(inputOrder);
	if (Order == "-rand")
		return 0;
	if (Order == "-sorted")
		return 1;
	if (Order == "-rev")
		return 2;
	if (Order == "-nsorted")
		return 3;
	return -1;
}

int convertStringToNum(char s[]) {
	int sum = 0;
	for (int i = 0; i < strlen(s); i++) {
		sum = sum * 10 + s[i] - '0';
	}
	return sum;
}

string GetAlgorithmName(char algorithmName[]) {
	string name(algorithmName);
	name[0] = name[0] - 32;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == '-') {
			name[i] = ' ';
			name[i + 1] = name[i + 1] - 32;
			break;
		}
	}
	return name;
}

string GetOutputParameter(char inputOrder[]) {
	string output(inputOrder);
	if (output == "-rand")
		return "Randomize";
	if (output == "-nsorted")
		return "Nearly sorted";
	if (output == "-rev")
		return "Reverse";
	if (output == "-sorted")
		return "Sorted";
	return "";
}

void PrintUndefinedErrorMessage() {
	cout << "ERROR! The Command Line does not match any type Specifier" << endl;
	cout << "Help: Here are the list of commands:" << endl;
	cout << "   Command 1: [Execution file name] -a [Algorithm]   [Given input]   [Output parameter(s)]" << endl;
	cout << "   Command 2: [Execution file name] -a [Algorithm]   [Input size]    [Input order]           [Output parameter(s)]" << endl;
	cout << "   Command 3: [Execution file name] -a [Algorithm]   [Input size]    [Output parameter(s)]" << endl;
	cout << "   Command 4: [Execution file name] -c [Algorithm 1] [Algorithm 2]   [Given input]" << endl;
	cout << "   Command 5: [Execution file name] -c [Algorithm 1] [Algorithm 2]   [Input size]            [Input order]" << endl;
	cout << "Make sure that your command line matches one of the above command parameters." << endl;
}

void PrintResultAlgorithmMode(char outputParameters[], double runtime, long long compare) {
	// print the run time if mode is time or both
	if (strcmp(outputParameters, "-time") == 0 || strcmp(outputParameters, "-both") == 0)
		cout << "Running time: " << runtime << " miliseconds." << endl;

	// print the comparison if mode is comp or both
	if (strcmp(outputParameters, "-comp") == 0 || strcmp(outputParameters, "-both") == 0)
		cout << "Comparisions: " << compare << " comparisions." << endl;
}

void PrintResultCompareMode(double runtime1, double runtime2, long long compare1, long long compare2) {
	// print the result of two algorithm: run time and comparison
	cout << "Running time: " << runtime1 << " | " << runtime2 << " miliseconds." << endl;
	cout << "Comparisions: " << compare1 << " | " << compare2 << " comparisions." << endl;
}
