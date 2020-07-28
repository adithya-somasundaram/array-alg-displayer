#include "sorting.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<double> selectionArr(argc - 1);
    vector<double> bubbleArr(argc - 1);

    for (int i = 1; i < argc; i++)
    {
        stringstream(argv[i]) >> selectionArr[i - 1];
    }
    copy(begin(selectionArr),end(selectionArr),bubbleArr.begin());

    cout << endl;
    selectionSort(selectionArr, argc - 1, true);
    bubbleSort(bubbleArr, argc - 1, true);

    return EXIT_SUCCESS;
}