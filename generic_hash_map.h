#ifndef GENERIC_HASH_MAP_H_INCLUDED
#define GENERIC_HASH_MAP_H_INCLUDED
#define HASH_MAP_SIZE 1007
#include<stdio.h>
#include "data_types.h"

void generic_hash_map_initialise(generic_hash_map** arr)
{
    (*arr)=malloc(sizeof(generic_hash_map));
    (*arr)->hash_array=(generic_array*)generic_array_intialise(HASH_MAP_SIZE,int_t);


}

void generic_hash_map_insert(generic_hash_map* arr,void* data,data_type_t type,int data_size)
{
    switch(type)
    {
    case char_t:
        generic_array_insert_ll( (arr)->hash_array,data,(*(char*)data)%HASH_MAP_SIZE,type);//,node_t),data_size);
        break;
    case int_t:
        generic_array_insert_ll( (arr)->hash_array,data,(*(int*)data)%HASH_MAP_SIZE,type);//node_t),data_size);
        break;
    case double_t:
        generic_array_insert_ll( (arr)->hash_array,data,( (int)(*(double*)data) )%HASH_MAP_SIZE,type);//node_t);,data_size);
        break;
    }
}

void generic_hash_map_print(generic_hash_map* arr)
{
    generic_array_print(arr->hash_array,node_t);
}

void generic_hash_map_remove(generic_hash_map* my_hash,void* data,data_type_t type)
{
    switch(type)
    {
    case char_t:
        ;
        char char_value=get_char(data);
        generic_ll_remove((&my_hash->hash_array->elements[char_value%HASH_MAP_SIZE]),data,type);
        break;
    case int_t:
        ;
        int int_value=get_int(data);
        generic_ll_remove(& (my_hash->hash_array->elements[int_value%HASH_MAP_SIZE]),data,type);
        break;
    case double_t:
        ;
        double double_value=get_double(data);
        generic_ll_remove(& (my_hash->hash_array->elements[ ( (int)double_value )%HASH_MAP_SIZE]),data,type);
        break;


    }

}

bool generic_hash_map_present(generic_hash_map* my_hash,void* data,data_type_t type)
{
     switch(type)
    {
    case char_t:
        ;
        char char_value=get_char(data);
        return generic_ll_present((&my_hash->hash_array->elements[char_value%HASH_MAP_SIZE]),data,type);
        break;
    case int_t:
        ;
        int int_value=get_int(data);
            return generic_ll_present(& (my_hash->hash_array->elements[int_value%HASH_MAP_SIZE]),data,type);
        break;
    case double_t:
        ;
        double double_value=get_double(data);
        return generic_ll_present(& (my_hash->hash_array->elements[ ( (int)double_value )%HASH_MAP_SIZE]),data,type);
        break;


    }
}
#endif // GENERIC_HASH_MAP_H_INCLUDED
