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

typedef struct{
    element* elements;
    int cursize;
}generic_array;
//declaring generic array and defining its current size

void* generic_array_intialise(unsigned n,data_type_t type)
{
    generic_array* arr=malloc(sizeof(generic_array));
    arr->elements=malloc(sizeof(element)*n);
    arr->cursize=0;
    for(int i=0;i<n;i++)
    {
        arr->elements[i].data=NULL;
    }
    return arr;
}

//insert at a particular index in the array
void generic_array_insert(void* arr,void* data, int index, int data_size)
{

    generic_array* garr=(generic_array*)arr;
    int temp=garr->cursize;

    while(temp!=index)
    {
       // printf("\n\n%s\n\n",garr->elements[temp]) ;
        garr->elements[temp].data=malloc(get_size(garr->elements[temp-1].type));
        memcpy(garr->elements[temp].data,garr->elements[temp-1].data,get_size(garr->elements[temp].type));
        garr->elements[temp].type=garr->elements[temp-1].type;
        temp--;
    }

    garr->elements[index].data=malloc(data_size);
    memcpy(garr->elements[index].data,data,data_size);
    garr->cursize++;
    switch(data_size)
    {
    case sizeof(char):
        garr->elements[index].type=char_t;
        break;
    case sizeof(int):
        garr->elements[index].type=int_t;
        break;
    case sizeof(double):
        garr->elements[index].type=double_t;
        break;
    default:
        garr->elements[index].type=string_t;
        break;

    }



}

void* generic_array_get(void* arr,int index)
{
    generic_array* garr=(generic_array*)arr;
    return garr->elements[index].data;
}


int get_size(data_type_t type)
{
    switch( type)
    {
    case char_t:
        return sizeof(char);
    case int_t:
        return sizeof(int);
    case double_t:
        return sizeof(double);
    }

}

void generic_array_print(void* arr)
{
    generic_array* garr=(generic_array*)arr;
    for(int i=0;i<garr->cursize;i++)
    {
        switch(garr->elements[i].type)
        {
            case char_t :
            printf("%c\n",*(char*)(garr->elements[i].data));
            break;
        case int_t :
            printf("%d\n",*(int*)(garr->elements[i].data));
            break;
        case double_t :
            printf("%f\n",*(double*)(garr->elements[i].data));
            break;
        case string_t:
            printf("%s\n",(char*)(garr->elements[i].data));
            break;

        }
    }

}

#endif // GENERIC_ARRAY1_H_INCLUDED
