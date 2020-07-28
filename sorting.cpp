#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print(vector<double> in, int len);
void write(ofstream &file, vector<double> in, int len);
void swap(vector<double> &in, int a, int b);

ofstream myfile;

void selectionSort(std::vector<double> arr, int len, bool notTest)
{
    if(notTest){
        myfile.open ("selectionSort.txt");
        myfile << "*** SELECTION SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,len);
        myfile << endl<<endl;
    }
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
        if(notTest) myfile << "Pass " << i << ": ";
        if (min != i) {
            swap(arr, i, min);
            print(arr, len);
            cout << " Swapped " << arr[i] << " with " << arr[min] << endl;
            if(notTest){
                write(myfile,arr,len);
                myfile << "| " << arr[min] << " is the largest element, so we swapped it to current index " << i << endl;
            }
        } else {
            cout << "Element at index " << i << " is less than elements to right of it -> no changes made" << endl;
            if(notTest){
                write(myfile,arr,len);
                myfile << "| Element at current index " << i << " is less than elements to right of it -> no changes made" << endl;
            }
        }
    }
    cout << "Final sorted array: ";
    print(arr,len);
    cout << endl << endl;
    if(notTest){
        myfile << endl << "Final sorted array: ";
        write(myfile,arr,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

void bubbleSort(std::vector<double> arr, int len, bool notTest){
    if(notTest){
        myfile.open ("bubbleSort.txt");
        myfile << "*** BUBBLE SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,len);
        myfile << endl;
    }
    cout << "*** BUBBLE SORT ***" << endl;
    cout << "Inputted array: ";
    print(arr, len);
    cout << endl;

    int i,j;

    for(i = 0; i < len; i++){
        cout << i << ": ";
        if(notTest) myfile << endl << "Pass " << i << ": ";
        for(j = 0; j < len-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
                if(notTest){
                    myfile << "Swapping " << arr[j] << " and " << arr[j+1] << " : ";
                    write(myfile,arr,len);
                    myfile << endl;
                }
            }
        }
        print(arr,len);
        cout << endl;
    }
    cout << "Final sorted array: ";
    print(arr,len);
    cout << endl << endl;
    if(notTest){
        myfile << endl << endl << "Final sorted array: ";
        write(myfile,arr,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

/* Helper functions */
void print(vector<double> in, int len)
{
    for (int a = 0; a < len; a++)
    {
        cout << in[a] << " ";
    }
}

void write(ofstream &file, vector<double> in, int len){
    for (int a = 0; a < len; a++)
    {
        file << in[a] << " ";
    }
}

void swap(vector<double> &in, int a, int b)
{
    double temp = in[a];
    in[a] = in[b];
    in[b] = temp;
}