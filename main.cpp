#include "sorting.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
    vector<double> arr(argc-1);
    for(int i = 1; i < argc; i++){
        stringstream(argv[i]) >> arr[i-1];
    }
    // std::copy(std::begin(og),std::end(og),arr.begin());
    selectionSort(arr, argc-1);
    return EXIT_SUCCESS;
}