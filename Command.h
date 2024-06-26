#pragma once
#include <iostream>
using namespace std;
string ConverString(char outputParameters[]);
void PrintResultAlgorithmMode(char outputParameters[], double runtime, long long compare);
// ----------------------- RUN COMMAND FUNCTIONS -----------------------------
void RunSorting(int arr[], int arrSize, char algorithmName[], char outputParameters[], double& runtime, long long& compare);
// function that runs the first command type:
void RunCommandTypeOne(char algorithmName[], char fileName[], char outputParameters[]);

// functions that runs the second command type:
void RunCommandTypeTwo(char algorithmName[], char inputSize[], char inputOrder[], char outputParameters[]);

// functions that runs the third command type:
void RunSpecificArrayOrderType(int arr[], int arrSize, int arrOrder, char algorithmName[], char outputParameters[], string fileName);
void RunCommandTypeThree(char algorithmName[], char inputSize[], char outputParameters[]);

// functions that runs the fourth command type:
void RunCommandTypeFour(char algorithmName1[], char algorithmName2[], char fileName[]);
// functions that runs the fifth command type:

void RunCommandTypeFive(char algorithmName1[], char algorithmName2[], char inputSize[], char inputOrder[]);

