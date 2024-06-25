#pragma once
#ifndef CHECK_PARAMETER
#define CHECK_PARAMETER

// function to check the parameters
bool isNumber(char s[]);							// check if the input parameter is a number;
bool isString(char s[]);							// check if the input parameter is a string
int convertStringToNum(char s[]);					// convert char to int type
bool isAlgorithmMode(char mode[]);					// check if the string matches the parameter for algorithm mode
bool isCompareMode(char mode[]);					// check if the string matches the parameter for comparison mode
bool isAlgorithmName(char algoName[]);				// check if the string matches the name of the sorting algorithm
bool isInputOrder(char inputOrder[]);				// check if the string matches the input order
int ArrayOrderType(char inputOrder[]);				// return the correctsponding input order of array based on the input command
bool isOutputParameters(char outputType[]);			// check if the string matches the output parameters
int AlgorithmType(char algoName[]);					// return the correctsponding algorithm that need to run
int OutputType(char outputType[]);

// Functions use to check the whole command parameters:
bool isCommandTypeOne(int argumentNum, char* argv[]);		// first command
bool isCommandTypeTwo(int argumentNum, char* argv[]);		// second command
bool isCommandTypeThree(int argumentNum, char* argv[]);		// third command
bool isCommandTypeFour(int argumentNum, char* argv[]);		// fourth command
bool isCommandTypeFive(int argumentNum, char* argv[]);		// fifth command



#endif 




