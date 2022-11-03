typedef void * Type;

typedef struct strArray *Array;

//Crear un Array del tamaño indicado por el parámetro size
//Permite almacenar tipos de datos que requieran los bytes indicados
Array createArray(unsigned int size, unsigned int bytes);  

//Retorna cuantos elementos contiene el arreglo
unsigned int sizeArray(Array);

//Retorna true si el arreglo se encuentra vacio y false en otro caso
unsigned int emptyArray(Array);

//Almacena un dato en la posición index del Array
//Para el manejo del index, considere que el Array es circular
void setArray(Array, int index, Type data);

//Retorna un apuntador al dato almacenado en la posición index del Array
//Para el manejo del index, considere que el Array es circular
Type getArray(Array, int index);

//Permite redimensionar el tamaño del arreglo sin perder los datos ya almacenados
Array resizeArray(Array, unsigned int newsize);

//Destruye el Array
void destroyArray(Array);