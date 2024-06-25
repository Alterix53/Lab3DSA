#include <iostream>
#include <cstring>
#include "CheckParameter.h"
#include "SortAndCountRuntime.h"
#include "Command.h"
#include "DataGenerator.h"
using namespace std;

int main(int argc, char* argv[]) {

	if (isCommandTypeOne(argc, argv)) {
		runCommandTypeOne(argc, argv);
	}
	else if (isCommandTypeTwo(argc, argv)) {
		cout << "loai 2";
	}
	else if (isCommandTypeThree(argc, argv)) {
		cout << "loai 3";
	}
	else if (isCommandTypeFour(argc, argv)) {
		cout << "loai 4";
	}
	else if (isCommandTypeFive(argc, argv)) {
		cout << "loai 5";
	}
	else {
		cout << "khong phai loai nao";
	}
		

	return 0;
}