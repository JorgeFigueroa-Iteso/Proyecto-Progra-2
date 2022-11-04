struct strNode{
	Type data;
	struct strNode *prior;
};

typedef struct strNode *Node;

struct strStack{
	Node top;
	size_t size_data;
	unsigned int size;
};

// Al ser público, lo pasamos al ".h" -> typedef struct strStack *Stack;

Stack stack_create(size_t bytes){
	Stack newStack=malloc(sizeof(struct strStack));
	newStack -> size_data = bytes;
	newStack -> size=0;
	newStack -> top=NULL;
	return newStack;
}

int stack_size(Stack s){
	if (s!=NULL){
		return s->size;
	} else{
		return -1;
	}
}

bool stack_isEmpty(Stack s){
	if (s!=NULL)
	{
		if (s->top!=NULL) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

// Nos permite leer el elemento que está por encima
Type stack_top(Stack s){
	if (s!=NULL) {
		if (stack_isEmpty(s)) {
			return NULL;
		}else{
			Type data_top=malloc(s->size_data);
			memcpy(data_top, s->top->data, s->size_data);
			// return s->top->data;
			return data_top;
		}
	}
	return NULL;
}

/* Crear un nuevo nodo
 * Y hacer el enlace al nuevo nodo que inicializamos
 */

Node newNode(Type data,size_t bytes){
	Node new=malloc(sizeof(struct strNode));
	new->data=malloc(bytes);
	memcpy(new->data, data, bytes);
	// new->data=data;
	new->prior=NULL;
	return new;
}

void stack_push(Stack s, Type data){
	if (s!=NULL) {									// ¿Existe el Stack?
		Node new = newNode(data, s->size_data);		// Crear nievo nodo e iniciar
		if (stack_isEmpty(s)) {
			s->top=new;
		}else {										// 
			new->prior=s->top;						// Agregar nodo enel tope
			s->top=new;								// Tope ahora apunta al nuevo nodo
		}
		s->size++;
	}
}

Type stack_pop(Stack s){

	if (s->size!=-1) {
/*		if (stack_isEmpty(s)) {
			return NULL;
		}else{*/
			// Apuntar a quien será el nuevo tope
			Node temp=s->top->prior;

			// Apuntar al dato que vamos a retornar
			Type data_pop=s->top->data;

			// Eliminar el tope actual
			free(s->top);

			// Mover top al nodo que es el nuevo top
			s->top=temp;
			s->size-=1;
			return data_pop;
		}
	return NULL;
}


void stack_destroy(Stack s){
	Type temp;
	while(!stack_isEmpty(s)){
		temp=stack_pop(s);
		free(temp);
	}
	free(s);
}
