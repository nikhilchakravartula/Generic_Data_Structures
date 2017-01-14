#ifndef GENERIC_QUEUE_H_INCLUDED
#define GENERIC_QUEUE_H_INCLUDED
#include "generic_ll.h"
typedef struct
{
    node* queue_head;
}Queue;
void generic_queue_initialise(Queue** q)
{
    (*q)=malloc(sizeof(Queue));
    (*q)->queue_head=malloc(sizeof(node));
    (*q)->queue_head->data=NULL;
    (*q)->queue_head->next=NULL;
}

void generic_queue_enqueue(Queue** q,void* data,int data_size)
{
    generic_ll_insert_head(&(*q)->queue_head,data,data_size);
}

void generic_queue_dequeue(Queue** q)
{
    return generic_ll_pop_head(& ((*q)->queue_head)) ;
}

void* generic_queue_get_head(Queue** q)
{
    return generic_ll_get_head( &((*q)->queue_head) );
}

void generic_queue_print(Queue** q)
{
    generic_ll_print( &((*q)->queue_head));
}
#endif // GENERIC_QUEUE_H_INCLUDED
