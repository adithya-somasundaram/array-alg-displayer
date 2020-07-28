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
    cout << endl;

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
            cout << " Swapped " << arr[i] << " with " << arr[min] << endl;
        } else {
            cout << "Element at index " << i << " is less than elements to right of it -> no changes made" << endl;
        }
    }
    cout << "Final sorted array: ";
    print(arr,len);
    cout << endl << endl;
}

void bubbleSort(std::vector<double> arr, int len){
    cout << "*** BUBBLE SORT ***" << endl;
    cout << "Inputted array: ";
    print(arr, len);
    cout << endl;

    int i,j;

    for(i = 0; i < len; i++){
        cout << i << ": ";
        for(j = 0; j < len-1; j++){
            if(arr[j] > arr[j+1]) swap(arr,j,j+1);
        }
        print(arr,len);
        cout << endl;
    }
    cout << "Final sorted array: ";
    print(arr,len);
    cout << endl << endl;
}

void print(vector<double> in, int len)
{
    for (int a = 0; a < len; a++)
    {
        cout << in[a] << " ";
    }
}

void swap(vector<double> &in, int a, int b)
{
    double temp = in[a];
    in[a] = in[b];
    in[b] = temp;
}