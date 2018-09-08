//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_SORTING_H
#define UNTITLED1_SORTING_H


#include "../PagedArray/PagedArray.h"

class Sorting {
public:


    static void quickSort(PagedArray *arr, int left, int right);
    static int partition(PagedArray *arr, int left, int right);

    static void insertionSort(PagedArray *arr, int length);
};


#endif//UNTITLED1_SORTING_H
