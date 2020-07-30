/*********************************************************
*
*   sorting.cpp - holds sorting methods and their helpers
*   Adithya Somasundaram, 7/29/2020
*
**********************************************************/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print(vector<double> in, int start, int len);
void write(ofstream &file, vector<double> in, int start, int len);
void swap(vector<double> &in, int a, int b);
void merge(vector<double> &arr, int left, int right, bool notTest);

ofstream myfile;

void selectionSort(std::vector<double> &arr, int len, bool notTest)
{
    // initial prints and writes
    if(notTest){
        myfile.open ("selectionSort.txt");
        myfile << "*** SELECTION SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,0,len);
        myfile << endl<<endl;
        cout << "*** SELECTION SORT ***" << endl;
        cout << "Inputted array: ";
        print(arr, 0, len);
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
                print(arr, 0, len);
                cout << " Swapped " << arr[i] << " with " << arr[min] << endl;
                write(myfile,arr,0,len);
                myfile << "| " << arr[i] << " was the smallest element to right of index, so we swapped it to current index " << i << endl;
            }
        } else {
            if(notTest){
                cout << "Element at index " << i << " is less than elements to right of it -> no changes made" << endl;
                write(myfile,arr,0,len);
                myfile << "| Element at current index " << i << " is less than elements to right of it -> no changes made" << endl;
            }
        }
    }

    // final prints and writes
    if(notTest){
        cout << "Final sorted array: ";
        print(arr, 0, len);
        cout << endl << endl;
        myfile << endl << "Final sorted array: ";
        write(myfile,arr,0,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

void bubbleSort(std::vector<double> &arr, int len, bool notTest){
    // initial prints and writes
    if(notTest){
        myfile.open ("bubbleSort.txt");
        myfile << "*** BUBBLE SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,0,len);
        myfile << endl;
        cout << "*** BUBBLE SORT ***" << endl;
        cout << "Inputted array: ";
        print(arr, 0, len);
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
                    write(myfile,arr,0,len);
                    myfile << endl;
                }
            }
        }
        if(notTest){
            print(arr, 0, len);
            cout << endl;
        }
    }
    
    // final prints and writes
    if(notTest){
        cout << "Final sorted array: ";
        print(arr, 0, len);
        cout << endl << endl;
        myfile << endl << endl << "Final sorted array: ";
        write(myfile,arr,0,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

void insertionSort(std::vector<double> &arr, int len, bool notTest){
    if(notTest){
        myfile.open ("insertionSort.txt");
        myfile << "*** INSERTION SORT ***" << endl;
        myfile << "Inputted array: ";
        write(myfile,arr,0,len);
        myfile << endl;
        cout << "*** INSERTION SORT ***" << endl;
        cout << "Inputted array: ";
        print(arr, 0, len);
        cout << endl;
    }

    int i, copy;

    for(i = 1; i < len; i++){
        if(notTest){
            cout << i << ": ";
            myfile << endl << "Pass " << i << ": ";
        } 
        copy = i;
        while(arr[copy] < arr[copy-1] && copy > 0){
            swap(arr,copy,copy-1);
            if(notTest){
                myfile << "Swapped " << arr[copy] << " and " << arr[copy-1] << " : ";
                write(myfile,arr,0,len);
                myfile << endl;
            }
            copy = copy-1;
        }
        if(notTest){
            print(arr, 0, len);
            cout << " | Sorted up to index " << i << endl;
            myfile << "Sorted up to index " << i << endl;
        }
    }
    if(notTest){
        cout << "Final sorted array: ";
        print(arr, 0, len);
        cout << endl << endl;
        myfile << endl << "Final sorted array: ";
        write(myfile,arr,0,len);
        myfile << endl << "Runtime: O(n^2)";
        myfile.close();
    }
}

void mergeSort(std::vector<double> &arr, int left, int right, bool notTest, int level, ofstream &file){
    if(notTest){
        file << "Level from top: " << level << ", Index: [" << left  <<", "<< right <<"]: ";
        write(file,arr,left,right+1);
        file << endl;

        cout << "Level: " << level << ", Index: [" << left  <<", "<< right <<"]: ";
        print(arr, left, right+1);
        cout<< endl;
    }
    if(right > left){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid, notTest, level+1, file);
        mergeSort(arr, mid+1, right, notTest, level + 1, file);
        merge(arr, left, right, notTest);
    }
    if(notTest){
        file << "\tLevel from bottom (now merging): " << level << ", Index: [" << left  <<", "<< right <<"]: ";
        write(file,arr,left,right+1);
        file << endl;

        cout << " Post merge Level: " << level << ", Index: [" << left  <<", "<< right <<"]: ";
        print(arr, left, right+1);
        cout<< endl;
    }
}

/* Helper functions */
void print(vector<double> in, int start, int len)
{
    for (int a = start; a < len; a++)
    {
        cout << in[a] << " ";
    }
}

void write(ofstream &file, vector<double> in, int start, int len){
    for (int a = start; a < len; a++)
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

void merge(vector<double> &arr, int left, int right, bool notTest){
    
    int i,j = 0,k = 0;

    int mid = (left+right)/2;
    int left_bound = mid - left + 1;
    int right_bound = right - mid;

    vector<double> l;
    vector<double> r;

    for(i = 0; i < left_bound; i++){
        l.push_back(arr[left + i]);
    }
    for(i = 0; i < right_bound; i++){
        r.push_back(arr[mid + i + 1]);
    }

    i = left;

    while(j < left_bound && k < right_bound){
        if(l[j] < r[k]){
            arr[i] = l[j];
            j++;
        } else {
            arr[i] = r[k];
            k++;
        }
        i++;
    }

    while(j < left_bound){
        arr[i] = l[j];
        j++;
        i++;
    }

    while(k < right_bound){
        arr[i] = r[k];
        k++;
        i++;
    }
}