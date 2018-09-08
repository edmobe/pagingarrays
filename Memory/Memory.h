//
// Created by maria on 07/09/18.
//

#ifndef UNTITLED1_MEMORY_H
#define UNTITLED1_MEMORY_H
#include <iostream>
/**
  *@file Memory.h
  * @version 1.0
  * @date 15/3/18
  * @author Oscar Isaac Porras Perez
  * @title Memory
  * @brief Este archivo maneja todo lo que tiene que ver con la paginacion
  */
struct Page{
    int last_time_used = 0;
    int pos_init = -1;
    int pos_final = -1;
    int elements[100];
    int *page_num = (int*)malloc(sizeof(int));

};

/**
 * @brief Memory class es la clase que controla todo lo referente a el manejo de la paginacion
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
     * @brief este metodo busca la posicion del numero que se busca y retorna la pagina completa en la que se encuentra
     * @param posicion_numero la posicion del numero que se busca
     */
    Page* getPage(int pos);
    /**
     * @brief este metodo retorna el tamano del archivo que se esta leyendo, en este caso es archivo.bin
     * @return tamano en bytes del archivo
     */
    int *getSize();
    /**
     * @brief este metodo inserta la pagina entera(que se busca en el metodo cargarpagina) en los arrays de la memoria.
     * @param paginainsertar
     */
    Page* insert(struct Page *insertPage);

    int& operator[](int index);


};


#endif //UNTITLED1_MEMORY_H
