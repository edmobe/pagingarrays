//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_READER_H
#define UNTITLED1_READER_H


/**
  *@file Reader.h
  * @version 1.0
  * @title Reader
  * @brief This class gets the info of the file that will be sorted
 **/
class Reader {
private:
    const char* Path;
public:
    /**
     * @brief Initializes el objeto Reader
     */
    Reader();

    /**
     *@brief Writes the random integers in the archivo.bin file
     */
    void writeFile();
    /**
     * @brief Reads archivo.bin (not used)
     */
    void readFile();
    /**
     * @brief gives the size of the file (not used)
     */
    long getSize();
};


#endif