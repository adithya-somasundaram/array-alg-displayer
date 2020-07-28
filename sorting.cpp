#include <iostream>
#include <vector>

using namespace std;

void print(vector<double> in, int len);
void swap(vector<double> &in, int a, int b);

void selectionSort(std::vector<double> arr, int len)
{
    cout << "*** SELECTION SORT ***" << endl;
    cout << "Inputted array: ";
    print(arr, len);

    int j, min;

    for (int i = 0; i < len; i++)
    {
        min = i;
        for (j = i; j < len; j++){
            if (arr[min] > arr[j]) min = j;
        }
        cout << i << ": ";
        if (min != i) {
            swap(arr, i, min);
            print(arr, len);
        } else {
            cout << "Element at index " << i << " is less than elements to right of it -> no changes made" << endl;
        }
    }
}

void print(vector<double> in, int len)
{
    for (int a = 0; a < len; a++)
    {
        cout << in[a] << " ";
    }
    cout << endl;
}

void swap(vector<double> &in, int a, int b)
{
    double temp = in[a];
    in[a] = in[b];
    in[b] = temp;
}