#include <iostream>
#include <cstring>
#include "CheckParameter.h"
#include "SortAndCountRuntime.h"
#include "Command.h"
#include "DataGenerator.h"
using namespace std;

int main(int argc, char* argv[]) {

	if (isCommandTypeOne(argc, argv)) {
		RunCommandTypeOne(argv[2], argv[3], argv[4]);
	}
	else if (isCommandTypeTwo(argc, argv)) {
		RunCommandTypeTwo(argv[2], argv[3], argv[4], argv[5]);
	}
	else if (isCommandTypeThree(argc, argv)) {
		RunCommandTypeThree(argv[2], argv[3], argv[4]);
	}
	else if (isCommandTypeFour(argc, argv)) {
		RunCommandTypeFour(argv[2], argv[3], argv[4]);
	}
	else if (isCommandTypeFive(argc, argv)) {
		RunCommandTypeFive(argv[2], argv[3], argv[4], argv[5]);
	}
	else {
		cout << "ERROR! The Command Line does not match any type Specifier" << endl;
		cout << "Help: There are five command lines with diffent functions:" << endl;
		cout << "   Command 1: [Execution file name] -a [algorithm]   [given input]   [output parameters]" << endl;
		cout << "   Command 2: [Execution file name] -a [Algorithm]   [Input size]    [Input order]           [Output parameter(s)]" << endl;
		cout << "   Command 3: [Execution file name] -a [Algorithm]   [Input size]    [Output parameter(s)]" << endl;
		cout << "   Command 4: [Execution file name] -c [Algorithm 1] [Algorithm 2]   [Given input]" << endl;
		cout << "   Command 5: [Execution file name] -c [Algorithm 1] [Algorithm 2]   [Input size]            [Input order]" << endl;
		cout << "Make sure that your command line matches one of the above command lines parameter." << endl;
	}
	return 0;
}