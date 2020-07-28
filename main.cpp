#include "sorting.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<double> arr(argc - 1);
    vector<double> arr2(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        stringstream(argv[i]) >> arr[i - 1];
    }
    copy(begin(arr),end(arr),arr2.begin());

    cout << endl;
    selectionSort(arr, argc - 1);
    bubbleSort(arr2, argc - 1);
    return EXIT_SUCCESS;
}