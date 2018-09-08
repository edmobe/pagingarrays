//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_READER_H
#define UNTITLED1_READER_H


/**
  *@file Reader.h
  * @version 1.0
  * @date 9/6/18
  * @author Gabriel Abarca Aguilar
  * @title Reader
  * @brief this class gets the info of the file that will be sorted
 **/
class Reader {
private:
    const char* Path;
public:
    /**
     * @brief Inicializa el objeto Reader
     */
    Reader();

    /**
     *@brief Escribe los numeros aleatorios en el archivo.bin
     */
    void writeFile();
    /**
     * @brief lee el archivo.bin. NO SE USA
     */
    void readFile();
    /**
     * @brief da el tamano real del archivo, no de lo que contiene en numeros binarios. NO SE USA
     */
    long getSize();
};


#endif