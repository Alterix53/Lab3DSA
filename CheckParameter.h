#pragma once
#ifndef CHECK_PARAMETER
#define CHECK_PARAMETER

// function to check the parameters
bool isNumber(char s[]);							// check if the input parameter is a number;
bool isString(char s[]);							// check if the input parameter is a string
bool isAlgorithmMode(char mode[]);					// check if the string matches the parameter for algorithm mode
bool isCompareMode(char mode[]);					// check if the string matches the parameter for comparison mode
bool isAlgorithmName(char algoName[]);				// check if the string matches the name of the sorting algorithm
bool isInputOrder(char inputOrder[]);				// check if the string matches the input order
bool isOutputParameters(char outputType[]);			// check if the string matches the output parameters

// Functions use to check the whole command parameters:
bool isCommandTypeOne(int argumentNum, char* argv[]);		// first command
bool isCommandTypeTwo(int argumentNum, char* argv[]);		// second command
bool isCommandTypeThree(int argumentNum, char* argv[]);		// third command
bool isCommandTypeFour(int argumentNum, char* argv[]);		// fourth command
bool isCommandTypeFive(int argumentNum, char* argv[]);		// fifth command



#endif 




