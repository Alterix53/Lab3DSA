#pragma once
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

// file read/write function
void WriteArrayToFile(int* arr, int arrSize, string fileName);		// write array into file
int* ReadArrayFromFile(int& arrSize, string fileName);				// read array from file

// Functions that help in convert data type
int AlgorithmType(char algoName[]);					// return the correctsponding algorithm that need to run
int OutputType(char outputType[]);					// return the result base on output parameter
int ArrayOrderType(char inputOrder[]);				// return the correctsponding input order of array based on the input command
int convertStringToNum(char s[]);					// convert char[] type to int to process the command
string GetAlgorithmName(char algorithmName[]);		// function to get the name of the algorithm 
string GetOutputParameter(char outputParameters[]);	// function to get the output parameter name

// Functions that help to print message/result
void PrintUndefinedErrorMessage();					// function that print message if the command line is wrong
void PrintResultAlgorithmMode(char outputParameters[], double runtime, long long compare);				// print result command 1,2,3
void PrintResultCompareMode(double runtime1, double runtime2, long long compare1, long long compare2);	// print result command 4,5