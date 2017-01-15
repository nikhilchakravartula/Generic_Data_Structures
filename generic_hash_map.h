#ifndef GENERIC_HASH_MAP_H_INCLUDED
#define GENERIC_HASH_MAP_H_INCLUDED
#define HASH_MAP_SIZE 1007
#include<stdio.h>
#include "data_types.h"

void generic_hash_map_initialise(generic_hash_map** arr)
{
    (*arr)=malloc(sizeof(generic_hash_map));
        printf("in hash %d\n",(*arr)->hash_array->cursize);

    (*arr)->hash_array=generic_array_intialise(HASH_MAP_SIZE,int_t);
    printf("in hash %d\n",(*arr)->hash_array->cursize);

}

void generic_hash_map_insert(generic_hash_map** arr,void* data,data_type_t type,int data_size)
{
    switch(data_size)
    {
    case sizeof(char):
        generic_array_insert( (*arr)->hash_array,data,(*(char*)data)%HASH_MAP_SIZE,node_t,data_size);
        break;
    }
}

void generic_hash_map_print(generic_hash_map* arr)
{
    generic_array_print(arr);
}

#endif // GENERIC_HASH_MAP_H_INCLUDED
