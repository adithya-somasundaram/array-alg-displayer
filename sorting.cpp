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
    // initial prints and writes
    if(notTest){
        myfile.open ("selectionSort.txt");
        myfile << "*** SELECTION SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,len);
        myfile << endl<<endl;
        cout << "*** SELECTION SORT ***" << endl;
        cout << "Inputted array: ";
        print(arr, len);
        cout << endl;
    }

    int j, min;     // local vars

    for (int i = 0; i < len; i++)
    {
        min = i;
        for (j = i; j < len; j++){
            if (arr[min] > arr[j]) min = j;
        }
        
        if(notTest){
            cout << i << ": ";
            myfile << "Pass " << i << ": ";
        } 
        if (min != i) {
            swap(arr, i, min);
            
            if(notTest){
                print(arr, len);
                cout << " Swapped " << arr[i] << " with " << arr[min] << endl;
                write(myfile,arr,len);
                myfile << "| " << arr[min] << " is the largest element, so we swapped it to current index " << i << endl;
            }
        } else {
            if(notTest){
                cout << "Element at index " << i << " is less than elements to right of it -> no changes made" << endl;
                write(myfile,arr,len);
                myfile << "| Element at current index " << i << " is less than elements to right of it -> no changes made" << endl;
            }
        }
    }

    // final prints and writes
    if(notTest){
        cout << "Final sorted array: ";
        print(arr,len);
        cout << endl << endl;
        myfile << endl << "Final sorted array: ";
        write(myfile,arr,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

void bubbleSort(std::vector<double> arr, int len, bool notTest){
    // initial prints and writes
    if(notTest){
        myfile.open ("bubbleSort.txt");
        myfile << "*** BUBBLE SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,len);
        myfile << endl;
        cout << "*** BUBBLE SORT ***" << endl;
        cout << "Inputted array: ";
        print(arr, len);
        cout << endl;
    }

    int i,j;

    for(i = 0; i < len; i++){
        if(notTest){
            cout << i << ": ";
            myfile << endl << "Pass " << i << ": ";
        } 
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
        if(notTest){
            print(arr,len);
            cout << endl;
        }
    }
    
    // final prints and writes
    if(notTest){
        cout << "Final sorted array: ";
        print(arr,len);
        cout << endl << endl;
        myfile << endl << endl << "Final sorted array: ";
        write(myfile,arr,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

void insertionSort(std::vector<double> arr, int len, bool notTest){
    if(notTest){
        myfile.open ("insertionSort.txt");
        myfile << "*** INSERTION SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,len);
        myfile << endl;
        cout << "*** INSERTION SORT ***" << endl;
        cout << "Inputted array: ";
        print(arr, len);
        cout << endl;
    }

    int i, copy;

    for(i = 1; i < len; i++){
        if(notTest){
            cout << i << ": ";
            myfile << endl << "Pass " << i << ": ";
        } 
        copy = i;
        while(arr[copy] < arr[copy-1]){
            if(notTest){
                myfile << "Swapping " << arr[copy] << " and " << arr[copy-1] << " : ";
                write(myfile,arr,len);
                myfile << endl;
            }
            swap(arr,copy,copy-1);
            copy = copy-1;
        }
        if(notTest){
            print(arr,len);
            cout << " | Sorted up to index " << i << endl;
            myfile << "Sorted up to index " << i << endl;
        }
    }
    if(notTest){
        cout << "Final sorted array: ";
        print(arr,len);
        cout << endl << endl;
        myfile << endl << "Final sorted array: ";
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