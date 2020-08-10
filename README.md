# array-alg-displayer
This terminal application takes in a list of doubles and performs Bubble, Selection, Merge, and Quick sort
on the inputted list. The step by step process of each sorting algorithm is displayed back to the user in
the terminal. These steps are detailed further in each sorting algorithm's corresponding .out file, as to
not clutter the terminal too much.


## Running the application
After installation, to create the executable run:
```
g++ main.cpp sorting.cpp
```
Then to run:
```
./a.out [list of doubles seperated by space here]
```
Note: Quicksort is an unstable sorting algorithm, and will not always sort correctly based on input.

Last edited: 8/10/2020
