//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_SORTING_H
#define UNTITLED1_SORTING_H


#include "../PagedArray/PagedArray.h"

class Sorting {
public:

    /**
     * QuickSort algorithm
     * @param arr The PagedArray pointer
     * @param left Usually 0, the leftmost index
     * @param right The index number of the rightmost element
     */
    static void quickSort(PagedArray *arr, int left, int right);


    static int partition(PagedArray *arr, int left, int right);

    /**
     * Insertion sort algorithm
     * @param arr The PagedArray pointer to be sorted
     * @param length The number of elements in the array
     */
    static void insertionSort(PagedArray *arr, int length);
};


#endif//UNTITLED1_SORTING_H
