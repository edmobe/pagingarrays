//
// Created by maria on 07/09/18.
//

#include "Sorting.h"


void Sorting::quickSort(PagedArray *arr, int left, int right) {
    int index;
    if (left>=right){
        return;
    }
    index = partition(arr,left,right);
    quickSort(arr,left,index-1);
    quickSort(arr,index+1,right);

}

int Sorting::partition(PagedArray *arr, int left, int right) {
    int i,pindex = left;
    int tmp;
    int pivot = arr->operator[](right);

    /* partition */
    for (i=left;i<right;i++) {
        if (arr->operator[](i) <= pivot) {
            tmp = arr->operator[](pindex);
            arr->operator[](pindex) = arr->operator[](i);
            arr->operator[](i) = tmp;
            pindex++;
        }
    };

    tmp = arr->operator[](pindex);
    arr->operator[](pindex) = arr->operator[](right);
    arr->operator[](right) = tmp;
    return pindex;
}

void Sorting::insertionSort(PagedArray *arr, int length) {
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr->operator[](j - 1) > arr->operator[](j)) {
            tmp = arr->operator[](j);
            arr->operator[](j) = arr->operator[](j - 1);
            arr->operator[](j - 1) = tmp;
            j--;
        }
    }
}