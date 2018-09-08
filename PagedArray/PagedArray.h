//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_PAGEDARRAY_H
#define UNTITLED1_PAGEDARRAY_H


#include "../Memory/Memory.h"
#include <iostream>
#include <string>
using std::string;


/**
  *@file PagedArray.h
  * @version 1.0
  * @title PagedArray
  * @brief Manages the memory by paging
  */

/**
 * @brief Is a representation of each page that will be used for the paging
 */
class PagedArray {
public:
    /**
     * @brief Instantiation of the Memory class
     */
    Memory virtualMemory;
    int MAX_INDEX;

    PagedArray();
    int& operator[](int);
    void printAll();

    int *getSize();
};


#endif //UNTITLED1_PAGEDARRAY_H
