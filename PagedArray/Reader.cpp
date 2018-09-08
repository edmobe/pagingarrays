//
// Created by maria on 07/09/18.
//

#include <fstream>
using namespace std;

#include <iostream>
#include <sys/stat.h>
#include "Reader.h"

Reader::Reader() {

}

void Reader::writeFile() {

    Path = "archivo.bin";                                                                                               // Es el path al archivo
    ofstream file (Path, ios::out |ios::binary);                                                                        //Crea el archivo en binario

    int page = 2;                                                                                                     // Esta variable se usa para poder imprimir la pagina por la que va
    int ctr = 1;
    std::cout<<"****************************************Page: "<< 1 << std::endl;
    for(int i = 0; i < 1000; ++i){                                                                 //En este loop se escriben numeros random en el archivo
        if(ctr == 101){
            std::cout<<"****************************************Page: "<< page <<std::endl;
            page++;
            ctr = 1;
        }

        int num = 1 + rand()%(100-1);                                                                                    //Encuentra un numero random entre 1-10
        std::cout<<num<<","<< ctr << std::endl;                                                                   //Imprime el numero que se va a escibir y la posicion
        file.write ((char *) &num, sizeof(int));                                                                        //Escribe el numero
        ctr++;                                                                                     //Aumenta la posicion


    }

}

long Reader::getSize() {                                                                                                //Metodo que retorna el tamano en bytes del archivo
    struct stat results;
    if (stat("archivo.bin", &results) == 0){
        std::cout<< "El tamaño del archivo es : "<<results.st_size <<" bytes" <<std::endl;                              //Imprime el tamano del archivo
        return results.st_size;}

    else{
        std::cout<< "No se pudo determinar el tamano del archivo" <<std::endl;
        return 0;
    }
}

void Reader::readFile() {                                                                                               //Lee el archivo binario
    FILE *file;                                                                                                         //crea una variable de tipo File
    int number;
    file = fopen("archivo.bin","rb");                                                                                   //Abre el archivo
    if(file == nullptr){
        std::cout<<"Error: file didn't open."<< std::endl;
    }
    else{
        int ctr =0;
        while(fread(&number, sizeof(int),1,file)){                                                                      //En este loop mientras haya algo que leer lo imprime

            std::cout<<number<<", "<<ctr<<std::endl;
        }
    }

}