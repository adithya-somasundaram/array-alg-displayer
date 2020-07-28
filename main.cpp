#include "sorting.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

int main(int argc, char* argv[]){
    std::vector<double> arr(argc-1);
    for(int i = 1; i < argc; i++){
        std::stringstream(argv[i]) >> arr[i-1];
    }
    // std::copy(std::begin(og),std::end(og),arr.begin());
    selectionSort(arr, argc-1);
    return EXIT_SUCCESS;
}