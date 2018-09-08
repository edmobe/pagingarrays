//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_MEMORY_H
#define UNTITLED1_MEMORY_H
#include <iostream>

/**
  *@file Memory.h
  * @version 1.0
  * @title Memory
  * @brief Manages all about the paging
  */

/**
 * @brief Is a representation of each page that will be used for the paging
 */
struct Page{
    int last_time_used = 0;
    int pos_init = -1;
    int pos_final = -1;
    int elements[100];
    int *page_num = (int*)malloc(sizeof(int));

};

/**
 * @brief Manages the paging process
 */
class Memory{
public:
    Page Pages[4];
    struct Page First;
    struct Page Second;
    struct Page Third;
    struct Page Fourth;


public:

    Memory();


    /**
     * @brief Searches for the position of the entered number and returns the page it is in
     * @param Number_position the position of the number
     * @return Page the number is in
     */
    Page* getPage(int pos);

    /**
     * @brief Gets the size of the file that is being read archivo.bin
     * @return Size of the file in bytes
     */
    int *getSize();

    /**
     * @brief Loads the whole page to the arrays in memory
     * @param Page_to_insert
     */
    Page* insert(struct Page *insertPage);

    int& operator[](int index);


};


#endif //UNTITLED1_MEMORY_H
