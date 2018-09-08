#include <iostream>

#include <iostream>

#include "PagedArray/Reader.h"
#include "Memory/Memory.h"
#include "PagedArray/PagedArray.h"
#include "Sorting/Sorting.h"

using namespace std;

int main() {
    PagedArray array;
    cout << "Choose your fighter:\n 1. Quick sort \n 2.Insertion sort" << endl;


    int *length = array.getSize();
//    cout << "LENGTH: " << *length << endl;
    int fl = *length / 4;

    int input;
    cin >> input;
    if (input == 1) {
        Sorting::quickSort(&array, 0 , fl-1);
        array.printAll();
    } else if (input == 2) {
        Sorting::insertionSort(&array, fl);
        array.printAll();
    } else {
        cout << "input not valid, 1 or 2" << endl;
    }


    return 0;
}