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

bool isOutputParameters(char outputType[]) {
    if (!isString(outputType))
        return false;
    string output(outputType);
    if (output == "-time" || output == "-comp" || output == "-both")
        return true;
    return false;
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

// function to check if the input command is the third command prototype
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

// function to check if the input command is the fourth command prototype
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

// function to check if the input command is the fifth command prototype
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