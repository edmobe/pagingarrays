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

    Path = "archivo.bin";
    ofstream file (Path, ios::out |ios::binary);

    int page = 2;
    int ctr = 1;
    std::cout<<"****************************************Page: "<< 1 << std::endl;
    for(int i = 0; i < 1000; ++i){
        if(ctr == 101){
            std::cout<<"****************************************Page: "<< page <<std::endl;
            page++;
            ctr = 1;
        }

        int num = 1 + rand()%(100-1);
        std::cout<<num<<","<< ctr << std::endl;
        file.write ((char *) &num, sizeof(int));
        ctr++;


    }

}

long Reader::getSize() {
    struct stat results;
    if (stat("archivo.bin", &results) == 0){
        std::cout<< "El tamaño del archivo es : "<<results.st_size <<" bytes" <<std::endl;
        return results.st_size;}

    else{
        std::cout<< "No se pudo determinar el tamano del archivo" <<std::endl;
        return 0;
    }
}

void Reader::readFile() {
    FILE *file;
    int number;
    file = fopen("archivo.bin","rb");
    if(file == nullptr){
        std::cout<<"Error: file didn't open."<< std::endl;
    }
    else{
        int ctr =0;
        while(fread(&number, sizeof(int),1,file)){

            std::cout<<number<<", "<<ctr<<std::endl;
        }
    }

}