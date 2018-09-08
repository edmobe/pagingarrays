//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_PAGEDARRAY_H
#define UNTITLED1_PAGEDARRAY_H


#include "../Memory/Memory.h"
#include <iostream>
#include <string>
using std::string;

class PagedArray {
public:
    Memory virtualMemory;
    int MAX_INDEX;

    PagedArray();
    int& operator[](int);
    void printAll();

    int *getSize();
};


#endif //UNTITLED1_PAGEDARRAY_H
