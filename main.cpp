/************************************************
*
*   main.cpp - holds user input and main method
*   Adithya Somasundaram, 7/29/2020
*
*************************************************/

#include "sorting.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<double> original(argc - 1);
    vector<double> copy_arr(argc - 1);

    for (int i = 1; i < argc; i++)
    {
        stringstream(argv[i]) >> original[i - 1];
    }
    copy(begin(original),end(original),copy_arr.begin());

    cout << endl;
    selectionSort(copy_arr, argc - 1, true);
    copy(begin(original),end(original),copy_arr.begin());

    bubbleSort(copy_arr, argc - 1, true);
    copy(begin(original),end(original),copy_arr.begin());

    insertionSort(copy_arr, argc-1,true);
    copy(begin(original),end(original),copy_arr.begin());

    mergeSort(copy_arr, argc-1, true);
    copy(begin(original),end(original),copy_arr.begin());

    quickSort(copy_arr, argc-1, true);
    copy(begin(original),end(original),copy_arr.begin());

    return EXIT_SUCCESS;
}