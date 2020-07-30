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
#include <fstream>

using namespace std;
void write(ofstream &file, vector<double> in, int start, int len);

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

    cout << "*** MERGE SORT ***" <<endl;
    ofstream myfile;
    myfile.open ("mergeSort.txt");
    myfile << "*** MERGE SORT ***" << endl;
    mergeSort(copy_arr, 0, argc-2, true, 0, myfile);
    myfile << endl << "Final sorted array: ";
    write(myfile,copy_arr,0,argc-1);
    myfile << endl << "Runtime: O(nlog(n))";
    myfile.close();
    copy(begin(original),end(original),copy_arr.begin());

    return EXIT_SUCCESS;
}