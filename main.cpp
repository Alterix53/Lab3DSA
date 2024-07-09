#include "Command.h"

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
		PrintUndefinedErrorMessage();
	}
	return 0;
}

