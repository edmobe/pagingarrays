//
// Created by maria on 07/09/18.
//

#include <cmath>
#include <iostream>
#include "PagedArray.h"
#include "Reader.h"

PagedArray::PagedArray() {
    Reader reader;
    reader.writeFile();
    MAX_INDEX = 1000;
}

int& PagedArray::operator[](int index) {
    int requestedIndex = (index % 100);
    int requestedPageNumber = (int) ceil(index/100) + 1;
    struct Page* requestedPage = virtualMemory.getPage(index);


    for(int i = 0; i < 4; ++i){
        if(*virtualMemory.Pages[i].page_num == requestedPageNumber){
            requestedPage = &virtualMemory.Pages[i];
        }
    }

    return requestedPage->elements[requestedIndex];;
}


int *PagedArray::getSize() {
    return virtualMemory.getSize();
}


void PagedArray::printAll(){
    for(int x = 0; x < 4; x++) {
        Page page = virtualMemory.Pages[x];
        for (int i = 0; i < 100; i++) {
            std::cout << "Page: " << *page.page_num << " Position: " << i << " Value: " << page.elements[i]
            << std::endl;
            //std::cout <<  << " Position: " << i << " valor: " << page.elements[i]
                      //<< std::endl;

        }
        std::cout << "-------" << std::endl;
    }
}