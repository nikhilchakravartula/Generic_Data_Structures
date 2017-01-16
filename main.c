#include <stdio.h>
#include <stdlib.h>
#include "generic_array.h"
#include "generic_ll.h"
#include "generic_queue.h"
#include "data_types.h"
#include "generic_hash_map.h"
void test_generic_array()
{
    printf("\nTESTING GENERIC ARRAY\n");
    void* arr=generic_array_intialise(100,int_t);
    char ch='A';
    for(int i=0; i<4; i++)
    {
        //printf("here\n");
        generic_array_insert(arr,&ch,i,char_t,sizeof(char));
        ch++;
    }
    ch='A';
    for(int i=0; i<4; i++)
    {
        //printf("here\n");
        generic_array_remove_index(arr,i,char_t,sizeof(char));
        ch++;
    }
    int t=5;
    for(int i=0; i<5; i++)
    {
        generic_array_insert(arr,&t,i,int_t,sizeof(int));
        t++;
    }
    generic_array_insert(arr,&ch,2,char_t,sizeof(char));

    double d=5.6;
    for(int i=2; i<4; i++)
    {
        generic_array_insert(arr,&d,i,double_t,sizeof(double));
        d++;
    }

    generic_array_print(arr,other_t);

}
void test_generic_ll()
{
    printf("\nTESTING GENERIC LINKED LIST\n");
    node* head;
    generic_ll_intialise(&head);
    char ch='A';
    for(int i=0; i<4; i++)
    {
        generic_ll_insert_head(&head,&ch,sizeof(ch));
        ch++;
    }

    int t=5;
    for(int i=0; i<5; i++)
    {
        generic_ll_insert_head(&head,&t,sizeof(t));
        t++;
    }
    generic_ll_insert_tail(&head,&ch,sizeof(ch));

    double d=5.6;
    for(int i=2; i<4; i++)
    {
        generic_ll_insert_tail(&head,&d,sizeof(d));
        d++;
    }
    generic_ll_pop_head(&head);
    generic_ll_pop_head(&head);
    generic_ll_pop_head(&head);
    ch='B';
    generic_ll_remove(&head,&ch,char_t);
    ch='A';
    generic_ll_remove(&head,&ch,char_t);
    ch='E';
    generic_ll_remove(&head,&ch,char_t);
    int te=6;
    generic_ll_remove(&head,&te,int_t);
    generic_ll_print(&head);

}

void test_generic_queue()
{
    printf("\nTESTING GENERIC QUEUE\n");
    Queue* queue;
    generic_queue_initialise(&queue);
    char ch='A';

    for(int i=0; i<4; i++)
    {
        generic_queue_enqueue(&queue,&ch,sizeof(ch));
        ch++;
    }

    int t=5;
    for(int i=0; i<5; i++)
    {
        generic_queue_enqueue(&queue,&t,sizeof(t));
        t++;
    }
    generic_queue_enqueue(&queue,&ch,sizeof(ch));

    double d=5.6;
    for(int i=2; i<4; i++)
    {
        generic_queue_enqueue(&queue,&d,sizeof(d));
        d++;
    }
    generic_queue_dequeue(&queue);
    generic_queue_dequeue(&queue);
    generic_queue_dequeue(&queue);
    generic_queue_print(&queue);

}

void test_generic_hash_map()
{
    generic_hash_map* my_hash;
    generic_hash_map_initialise(&my_hash);
    //printf("cursize in main %d",my_hash->hash_array->cursize);
    char ch='A';
    for(int i=0; i<4; i++)
    {
        generic_hash_map_insert(my_hash,&ch,char_t,sizeof(ch));
        ch++;
    }

    for(int i=0; i<4; i++)
    {
        generic_hash_map_insert(my_hash,&ch,char_t,sizeof(ch));
        ch++;
    }

    int t=5;
    for(int i=0; i<5; i++)
    {
        generic_hash_map_insert(my_hash,&t,int_t,sizeof(t));
        t++;
    }
    int te=66;
    generic_hash_map_insert(my_hash,&ch,char_t,sizeof(ch));
    generic_hash_map_insert(my_hash,&te,int_t,sizeof(te));

    double d=5.6;
    for(int i=2; i<4; i++)
    {
        generic_hash_map_insert(my_hash,&d,double_t,sizeof(d));
        d++;
    }
    char data='B';
    generic_hash_map_remove(my_hash,&data,char_t);
    int v=6;
    generic_hash_map_remove(my_hash,&v,int_t);
    v=66;
    ch='A';
    generic_hash_map_remove(my_hash,&ch,char_t);

    generic_hash_map_print(my_hash);

}
int main()
{
    test_generic_hash_map();
    return 0;
}
