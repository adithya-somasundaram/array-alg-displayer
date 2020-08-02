/************************************************
*
*   test.cpp - testing harness for sorting algs
*   Needs to be compiled with c++11
*   Adithya Somasundaram, 8/1/2020
*
*************************************************/

#include "sorting.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
// #include <fstream>

#define TOTAL 5
#define TESTS 1

using namespace std;

int main(){

    // test vector and test result
    vector<double> test1 = {-5, 9.7, 12.5, 8, 15, 0, -1.6};
    vector<double> test1Res = {-5, -1.6, 0, 8, 9.7, 12.5, 15};
    int score = 0, local_score = 0;

    cout << "*** ARRAY DISPLAYER TESTING HARNESS ***" << endl << endl;

    // selection sort tests
    selectionSort(test1,7,false);
    if(equal(test1.begin(), test1.end(), test1Res.begin())){
        local_score++;
        score++;
    }
    cout << "Selection Sort: (" << local_score << "/" << TESTS << ") ";
    if(local_score == 1) cout << "PASSED";
    cout << endl; 

    // reset vars
    test1 = {-5, 9.7, 12.5, 8, 15, 0, -1.6};
    local_score = 0;

    // bubble sort tests
    bubbleSort(test1,7,false);
    if(test1 == test1Res){
        local_score++;
        score++;
    }
    cout << "Bubble Sort: (" << local_score << "/" << TESTS << ") ";
    if(local_score == 1) cout << "PASSED";
    cout << endl; 

    // reset vars
    test1 = {-5, 9.7, 12.5, 8, 15, 0, -1.6};
    local_score = 0;

    // insertion sort tests
    insertionSort(test1,7,false);
    if(test1 == test1Res){
        local_score++;
        score++;
    }
    cout << "Insertion Sort: (" << local_score << "/" << TESTS << ") ";
    if(local_score == 1) cout << "PASSED";
    cout << endl;

    // reset vars
    test1 = {-5, 9.7, 12.5, 8, 15, 0, -1.6};
    local_score = 0;

    // merge sort tests
    mergeSort(test1,7,false);
    if(test1 == test1Res){
        local_score++;
        score++;
    }
    cout << "Merge Sort: (" << local_score << "/" << TESTS << ") ";
    if(local_score == 1) cout << "PASSED";
    cout << endl; 

    // reset vars
    test1 = {-5, 9.7, 12.5, 8, 15, 0, -1.6};
    local_score = 0;

    // merge sort tests
    quickSort(test1,7,false);
    if(test1 == test1Res){
        local_score++;
        score++;
    }
    cout << "Quicksort: (" << local_score << "/" << TESTS << ") ";
    if(local_score == 1) cout << "PASSED";
    cout << endl; 

    // calculate final results
    cout << endl << "Final Score: (" << score << "/" << TOTAL << ") ";
    if(score == TOTAL) cout << "PASSED :)";
    cout << endl;

    return EXIT_SUCCESS;
}