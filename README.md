# Lab3DSA

## General Purpose
### Lab 3 is a project where users need to check the running time of 11 different sorting Algorithm:
#### - Selection sort
#### - Insertion sort
#### - Bubble sort
#### - Shaker sort
#### - Shell sort
#### - Heap sort
#### - Merge sort
#### - Quick sort
#### - Counting sort
#### - Radix sort
#### - Flash sort
### The experiments necessary for this project should be conducted following the below scenario.
for each Data Order S1
    for each Data Size S2
        for each Sorting Algorithm S3
            1. Create an array with Data Order S1 and Data Size S2
            2. Sort the created array using the Sorting Algorithm S3, while:
                + Measuring the running time (in millisecs), and
                + Counting the number of comparisons in the algorithm
            3. Take note of S1, S2, S3, running time and number of comparisons
        end for
    end for
end for

## Data Order:
### Examine the selected sorting algorithms on different data arrangements, including Sorted data (in ascending order), Nearly sorted data, Reverse sorted data, and Randomized data. See DataGenerator.cpp for more information.

## Data Size:
###  Examine the selected sorting algorithms on data of the following sizes: 10,000, 30,000, 50,000, 100,000, 300,000, and 500,000 elements.
