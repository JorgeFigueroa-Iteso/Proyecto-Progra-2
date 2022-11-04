#include "StackYQueue.h"

struct strNode{
    Type data;
    struct strNode *prior;
};

typedef struct strNode *Node;

struct strStack{
    Node top;
    unsigned int size;
    size_t bytes;
};

Stack stack_create(size_t bytes){
    Stack newstk = malloc(sizeof(struct strStack));

    newstk->bytes=bytes;
    newstk->size=0;
    newstk->top=NULL;
    return newstk;
}

int stack_size(Stack s){
    if (s!=NULL)
    {
        return s->size;
    }
    else
    {
        return -1;
    }
    
}

bool stack_isEmpty(Stack s)
{
    if (s != NULL)
    {
        if(s->top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
    
}

Type stack_top(Stack s)
{
    if (s!=NULL)
    {
        if(s->top!=NULL)
        {
            Type ret=malloc(s->bytes);
            memcpy(ret, s->top->data, s->bytes);
            return ret;
        }
        else 
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

Node newNode(Type data, size_t bytes)
{
    Node new= malloc(sizeof(struct strNode));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->prior=NULL;
    return new;
}

void stack_push(Stack s, Type data)
{
    if(s!=NULL)
    {
        Node nd=newNode(data, s->bytes);
        s->size++;
        nd->prior=s->top;
        s->top=nd;
    }
    else
    {
        printf("Error: Stack is null");
    }
}

Type stack_pop(Stack s)
{
    if(s!=NULL)
    {
        if(s->top!=NULL)
        {
            void *dataTemp=s->top->data;

            Node new_top=s->top->prior;
            free(s->top);
            s->top=new_top;
            s->size--;
            return dataTemp;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void stack_destroy(Stack s)
{
    if (s!=NULL)
    {
        if(s->top!=NULL && s->size!=0)
        {
            for(int i=0; i<s->size; i++)
            {
                if(s->top!=NULL)
                {
                    Node next_node=s->top->prior;
                    free(s->top->data);
                    free(s->top);
                    s->top=next_node;
                }
            }
        }
        free(s);
    }
}


struct nodeQE
{
    Type data;
    struct nodeQE *next;
};

typedef struct nodeQE * NodePQ;

struct strQueue
{
    NodePQ first;
    NodePQ last;
    int size;
    size_t size_data;
};


Queue queueCreate(size_t bytes)
{
    Queue new=malloc(sizeof(struct strQueue));
    new->first=NULL;
    new->last=NULL;
    new->size_data=bytes;
    new->size=0;
    return new;
}

int queueSize(Queue q1)
{
    if(q1!=NULL)
    {
        return q1->size;
    }
    else
    {
        return 0;
    }
}

bool queueEmpty(Queue q1)
{
    if(q1!=NULL)
    {
        if(q1->size==0 && q1->first==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }

}

NodePQ newNodeP(Type data, size_t bytes)
{
    NodePQ new=malloc(sizeof(struct nodeQE));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->next=NULL;
    return new;
}

void enqueue(Queue q, Type data)
{
    if(q!=NULL)
    {
        NodePQ new=newNodeP(data, q->size_data);
        if(queueEmpty(q))
        {
            q->first=new;
            q->last=new;
            q->size++;
        }
        else
        {
            q->last->next=new;
            q->last=new;
            q->size++;
        }
    }
}

Type peek(Queue q)
{
    if (q!=NULL)
    {
        if( !queueEmpty(q))
        {
            return q->first->data;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
    
}

Type dequeue(Queue q)
{
    if (q!=NULL)
    {
        if(!queueEmpty(q))
        {
            NodePQ ret=q->first;
            Type temp=ret->data;
            
            if(ret->next!=NULL){
                q->first=ret->next;

            }
            else
            {
                q->first=NULL;
            }
            free(ret);
            q->size--;
            return temp;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
    
}

void queueDestroy(Queue q)
{
    if(q!=NULL)
    {
        Type temp;
        while (!queueEmpty(q))
        {
            temp=dequeue(q);
            free(temp);
        }
        free(q);
    }
}