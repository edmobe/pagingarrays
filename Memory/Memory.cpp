//
// Created by maria on 07/09/18.
//

#include "Memory.h"
#include <iostream>
#include <string>
using std::string;

/**
  *@file Memory.h
  * @version 1.0
  * @date
  * @author Gabriel Abarca
  * @title Memory
  * @brief this manages de pages and the Memory.
  */


Memory::Memory() {


    *First.page_num = -1;

    *Second.page_num = -1;

    *Third.page_num = -1;

    *Fourth.page_num = -1;

}

int *
Memory::getSize() {                                                                                                  //Este metodo no se utiliza
    FILE *file;
    int number;
    file = fopen("archivo.bin","rb");
    int *data = (int *)malloc(sizeof(int));
    *data = 0;
    if(file==NULL){
        std::cout<<"no se abrio"<< std::endl;
    }
    else{
        while(fread(&number, sizeof(int),1,file)){
            *data = *data + 1;
        }
    }
    *data = *data * sizeof(int);
    return data;
}

Page* Memory::insert(Page *insertPage) {
    if(*First.page_num == -1){

        First.page_num = insertPage->page_num;


        for(int x = 0; x < 101; ++x){
            First.elements[x] = insertPage->elements[x];
        }

        Pages[0] = First;

        First.last_time_used += 1;

        return &First;
    }
    if(*Second.page_num == -1){

        Second.page_num = insertPage->page_num;


        Second.last_time_used += 1;
        for(int x= 0; x < 101; ++x){
            Second.elements[x] = insertPage->elements[x];
        }
        Pages[1] = Second;
        return &Second;
    }
    if(*Third.page_num == -1) {
        Third.page_num = insertPage->page_num;


        Third.last_time_used +=1;
        for(int x=0; x < 101; ++x){
            Third.elements[x] = insertPage->elements[x];
        }
        Pages[2] = Third;
        return &Third;
    }
    if(*Fourth.page_num == -1){
        Fourth.page_num = insertPage->page_num;

        Fourth.last_time_used +=1;
        for(int x = 0 ; x < 101; ++x){
            Fourth.elements[x] = insertPage->elements[x];
        }
        Pages[3] = Fourth;
        return &Fourth;
    }
    else{
        if(First.last_time_used >= Second.last_time_used && First.last_time_used>= Third.last_time_used
           && First.last_time_used>= Fourth.last_time_used)
        {
            First.page_num = insertPage->page_num;
            for(int x=0; x < 101; ++x){
                First.elements[x] = insertPage->elements[x];
            }
            Pages[0] = First;
            return &First;
        }
        if(Second.last_time_used>= First.last_time_used && Second.last_time_used>= Third.last_time_used
           && Second.last_time_used>= Fourth.last_time_used){
            Second.page_num = insertPage->page_num;
            for(int x=0; x < 101; ++x){
                Second.elements[x] = insertPage->elements[x];
            }
            Pages[1] = Second;
            return &Second;
        }
        if(Third.last_time_used>= First.last_time_used && Third.last_time_used>= Second.last_time_used
           && Third.last_time_used>= Fourth.last_time_used){

            Third.page_num = insertPage->page_num;
            for(int x=0; x < 101; ++x){
                Third.elements[x] = insertPage->elements[x];
            }
            Pages[2] = Third;
            return &Third;
        }
        if(Fourth.last_time_used>= First.last_time_used && Fourth.last_time_used>= Second.last_time_used
           && Fourth.last_time_used>= Third.last_time_used){
            //std::cout<<"SE INSERTO EN LA PAGINA 4 POR LIFO"<<std::endl;
            Fourth.page_num = insertPage->page_num;
            for(int x=0; x < 101; ++x){
                Fourth.elements[x] = insertPage->elements[x];
            }
            Fourth = (*insertPage);
            Pages[3] = Fourth;

            return &Fourth;
        }

    }
}

Page* Memory::getPage(int pos) {
    int status = 0;//Not Charged
    int bytepos = pos * sizeof(int);
    float page_num = (float(bytepos) / (sizeof(int) * 100));

    if(page_num > int(page_num)){
        page_num = int(page_num + 1);
    }
    else{
        page_num = int(page_num);
    }
    if(pos%100 == 0)
        page_num += 1;


    if (page_num == *First.page_num){
        First.last_time_used += 1;

        return &First;
    }

    if(page_num == *Second.page_num){
        Second.last_time_used +=1;
        return &Second;
    }
    if( page_num == *Third.page_num ){
        Third.last_time_used +=1;
        return &Third;
    }
    if(page_num == *Fourth.page_num){
        Fourth.last_time_used +=1;
        return &Fourth;
    }


    if (status == 0) {//Not Charged                                                                                         //Si la pagina no esta normal


        FILE *file;
        file = fopen("archivo.bin", "rb");                                                                               //Abre el archivo.bin

        if (page_num == 1) {
            //Si el elemento se encuentra en la pagina 1 entonces  no lo multiplica por la cantidad de bytes que tiene cada pagina
            fseek(file, 0, SEEK_SET);
        }

        if (page_num != 1) {                                                                                       //Si el elemento no es la primera multiplica la pagina por la cantidad de bytes que tiene cada pagina
            //...y de esta manera posiciona el lector del archivo donde va a empezar leer la pagina
            fseek(file, (int(page_num)-1) * 400, SEEK_SET);
        }

        int index = 0;

        Page tempPage;                                                                                                //Crea la pagina

        *tempPage.page_num = int(page_num);
        // Le asigna el numero de la pagina
        if(page_num == 1){
            tempPage.pos_init = 0;
        }
        if(page_num != 1){
            tempPage.pos_init = int(page_num) * 400;
        }
        //Le asigna la index inicial de la pagina

        tempPage.pos_final = (int(page_num)+1) * 400;


        //Le asigna la index final de la pagina

        int number;
        int counter = 0;

        while (fread(&number, sizeof(int), 1, file) && counter != 101) {                                                  //Aca lee el archivo y le mete los numeros al array que tiene la pagina

            tempPage.elements[index] = number;                                                                       //Aca mete los numeros al array
            index = index + 1;                                                                                    //Aumenta la index
            counter = counter + 1;
        }


        insert(&tempPage);                                                                                       //Inserta la pagina creada en los memoria

    }

}