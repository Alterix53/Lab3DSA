#pragma once
#include <iostream>
#include "CheckParameter.h"
#include "SortAndCountRuntime.h"
#include "SortAndCountCompare.h"
#include "DataGenerator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;
string ConverString(char outputParameters[]);
void PrintResultAlgorithmMode(char outputParameters[], double runtime, long long compare);
// ----------------------- RUN COMMAND FUNCTIONS -----------------------------

// Function that runs the correctspoding sorting algorithm(s):
void RunSorting(int *a, int arrSize, char algorithmName[], char outputParameters[], double& runtime, long long& compare);

// Function that runs the sorting algorithm on a specific array order
// This function is used in the third command
void RunSpecificArrayOrderType(int *a, int arrSize, int arrOrder, char algorithmName[], char outputParameters[], string fileName);

// Functions that run the command based on current command line:
void RunCommandTypeOne(char algorithmName[], char fileName[], char outputParameters[]);							// first command line
void RunCommandTypeTwo(char algorithmName[], char inputSize[], char inputOrder[], char outputParameters[]);		// second command line
void RunCommandTypeThree(char algorithmName[], char inputSize[], char outputParameters[]);						// third command line
void RunCommandTypeFour(char algorithmName1[], char algorithmName2[], char fileName[]);							// fourth command line
void RunCommandTypeFive(char algorithmName1[], char algorithmName2[], char inputSize[], char inputOrder[]);		// fifth command line

