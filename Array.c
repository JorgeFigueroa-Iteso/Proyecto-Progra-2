// juan.alonso@iteso.mx
#include "Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct strArray{
    void *data;
    unsigned int size_data;
    unsigned size;
};

//Crear un Array del tamaño indicado por el parámetro size
//Permite almacenar tipos de datos que requieran los bytes indicados
Array createArray(unsigned int size, unsigned int bytes){
    if(bytes>0){
        Array new=malloc(sizeof(struct strArray));
        new->size=size;
        new->size_data=bytes;
        new->data=calloc(size, bytes);
        return new;
    }
    return NULL;
}

//Retorna cuantos elementos contiene el arreglo
unsigned int sizeArray(Array a){
    if(a!=NULL)
        return a->size;
    return 0;
}


int mod(int a, int b){
    return a - (a / b) * b;
}

//Almacena un dato en la posición index del Array
//Para el manejo del index, considere que el Array es circular
void setArray(Array a, int index, Type data){
    int p;
    if(index>0){
        p=index%a->size;
    }
    else{
        p=a->size+(mod(index,a->size));
        if(p==a->size) p=0;
    }
    memcpy(a->data+(p*a->size_data), data, a->size_data);
}

//Retorna un apuntador al dato almacenado en la posición index del Array
//Para el manejo del index, considere que el Array es circular
Type getArray(Array a, int index){
    int p;
    if(index>0){
        p=index%a->size;
    } else{
        p=a->size+mod(index,a->size);
        if(p==a->size) p=0;
    }
    return a->data+(p*a->size_data);
}

//Permite redimensionar el tamaño del arreglo sin perder los datos ya almacenados
Array resizeArray(Array, unsigned int newsize);

//Destruye el Array
void destroyArray(Array);