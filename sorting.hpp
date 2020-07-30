#ifndef SORTING
#define SORTING

#include <iostream>
#include <vector>
#include <fstream>

void selectionSort(std::vector<double> &arr, int len, bool notTest);
void bubbleSort(std::vector<double> &arr, int len, bool notTest);
void insertionSort(std::vector<double> &arr, int len, bool notTest);
void mergeSort(std::vector<double> &arr, int left, int right, bool notTest, int level, std::ofstream &file);

#endif