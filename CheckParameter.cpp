#include "CheckParameter.h"
#include <iostream>
#include <string> 
#include <cstring>
using namespace std;

bool isAlgorithmName(char algoName[]) {
    if (!isString(algoName))
        return false;
    string name(algoName);
    if (name == "selection-sort" || name == "insertion-sort"
        || name == "bubble-sort" || name == "shaker-sort" || name == "shell-sort"
        || name == "heap-sort" || name == "merge-sort" || name == "quick-sort"
        || name == "counting-sort" || name == "radix-sort" || name == "flash-sort")
        return true;
    else return false;
}

bool isInputOrder(char inputOrder[]) {
    if (!isString(inputOrder))
        return false;

    string Order(inputOrder);
    if (Order == "-rand" || Order == "-nsorted" || Order == "-sorted" || Order == "-rev")
        return true;
    return false;
}

int ArrayOrderType(char inputOrder[]) {
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

bool isOutputParameters(char outputType[]) {
    if (!isString(outputType))
        return false;
    string output(outputType);
    if (output == "-time" || output == "-comp" || output == "-both")
        return true;
    return false;
}

int OutputType(char outputType[]) {
    string output(outputType);
    if (output == "time")
        return 0;
    if (output == "-comp")
        return 1;
    if (output == "-both")
        return 2;
    return -1;
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

bool isAlgorithmMode(char mode[]) {
    return (strcmp(mode, "-a") == 0);
}

bool isCompareMode(char mode[]) {
    return (strcmp(mode, "-c") == 0);
}



bool isNumber(char s[])
{
    for (int i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            return false;
        }
    }
    return true;
}

bool isString(char s[]) {
    return !isNumber(s);
}

int convertStringToNum(char s[]) {
    int sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        sum = sum * 10 + s[i] - '0';
    }
    return sum;
}

// check if the prototype calls the first command type
bool isCommandTypeOne(int argumentNum, char* argv[]) {

    // check each part of the command inputs, return false if any of them does not match the correct prototype
    if (argumentNum != 5)
        return false;
    if (!isAlgorithmMode(argv[1]))
        return false;
    if (!isAlgorithmName(argv[2]))
        return false;
    if (!isString(argv[3]))
        return false;
    if (!isOutputParameters(argv[4]))
        return false;

    return true;    // all are correct
}

// check the second command, using the exact above method
bool isCommandTypeTwo(int argumentNum, char* argv[]) {
    if (argumentNum != 6)
        return false;
    if (!isAlgorithmMode(argv[1]))
        return false;
    if (!isAlgorithmName(argv[2]))
        return false;
    if (!isNumber(argv[3]))
        return false;
    if (!isInputOrder(argv[4]))
        return false;
    if (!isOutputParameters(argv[5]))
        return false;
    return true;
}

bool isCommandTypeThree(int argumentNum, char* argv[]) {

    // check each part of the command inputs, return false if any of them does not match the correct prototype
    if (argumentNum != 5)
        return false;
    if (!isAlgorithmMode(argv[1]))
        return false;
    if (!isAlgorithmName(argv[2]))
        return false;
    if (!isNumber(argv[3]))
        return false;
    if (!isOutputParameters(argv[4]))
        return false;
    return true;
}

bool isCommandTypeFour(int argumentNum, char* argv[]) {
    if (argumentNum != 5)
        return false;
    if (!isCompareMode(argv[1]))
        return false;
    if (!isAlgorithmName(argv[2]))
        return false;
    if (!isAlgorithmName(argv[3]))
        return false;
    if (!isString(argv[4]))
        return false;
    return true;
}

bool isCommandTypeFive(int argumentNum, char* argv[]) {
    if (argumentNum != 6)
        return false;
    if (!isCompareMode(argv[1]))
        return false;
    if (!isAlgorithmName(argv[2]))
        return false;
    if (!isAlgorithmName(argv[3]))
        return false;
    if (!isNumber(argv[4]))
        return false;
    if (!isInputOrder(argv[5]))
        return false;
    return true;
}