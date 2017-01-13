#ifndef GENERIC_ARRAY_H_INCLUDED
#define GENERIC_ARRAY_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include "data_types.h"
#define MAX_SIZE 10000000

// defining array struct
typedef struct
{
    void* data;
    data_type_t type;
} element;

//declaring generic array and defining its current size
element generic_array[MAX_SIZE];
unsigned generic_array_cursize=0;

void generic_array_intialise()
{
    for (int i=0; i<MAX_SIZE; i++)
    {
        generic_array[i].data=NULL;
    }
}

//insert at a particular index in the array
void generic_array_insert(void* data, int index, int data_size)
{
    int temp=generic_array_cursize;

    while(temp!=index)
    {
        generic_array[temp].data=malloc(get_size(generic_array[temp-1]));
        memcpy(generic_array[temp].data,generic_array[temp-1].data,get_size(generic_array[temp]));
        generic_array[temp].type=generic_array[temp-1].type;
        temp--;
    }
    generic_array[index].data=malloc(data_size);
    memcpy(generic_array[index].data,data,data_size);
    generic_array_cursize+=1;
    switch(data_size)
    {
    case sizeof(char):
        generic_array[index].type=char_t;
        break;
    case sizeof(int):
        generic_array[index].type=int_t;
        break;
    case sizeof(double):
        generic_array[index].type=double_t;
        break;
    default:
        generic_array[index].type=string_t;
        break;

    }



}

void* generic_array_get(int index)
{
    return generic_array[index].data;
}

void generic_array_print()
{
    for(int index=0; index<generic_array_cursize; index++)
    {
        switch(generic_array[index].type)
        {
        case char_t :
            printf("%c\n",*(char*)generic_array[index].data);
            break;
        case int_t :
            printf("%d\n",*(int*)generic_array[index].data);
            break;
        case double_t :
            printf("%f\n",*(double*)generic_array[index].data);
            break;
        case string_t:
            printf("%s\n",(char*)generic_array[index].data);
            break;

        }
    }
}

int get_size(element data)
{
    switch( data . type)
    {
    case char_t:
        return sizeof(char);
    case int_t:
        return sizeof(int);
    case double_t:
        return sizeof(double);
    case string_t:
        return sizeof( data. data);
    }

}
#endif // GENERIC_ARRAY_H_INCLUDED
