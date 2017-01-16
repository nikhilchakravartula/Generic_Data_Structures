#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED
#include<stdbool.h>

typedef enum
{
    char_t,
    int_t,
    double_t,
    node_t,
    my_data_struct_t,
    other_t
} data_type_t;

typedef struct llnode
{
    void* data;
    data_type_t type;
    struct llnode* next;
} node;

typedef struct
{
    void* data;
    data_type_t type;
} element;
typedef struct
{
    element* elements;
    int cursize;
} generic_array;

typedef struct
{
    generic_array* hash_array;

} generic_hash_map;

char get_char(void* data)
{
    return *(char*)data;
}

int get_int(void* data)
{
    return *(int*)data;
}

double get_double(void* data)
{
    return *(double*)data;
}

node* get_node(void* data)
{
    return  (node*)data;
}

typedef struct{

char ch;
int in;
double db;
}my_data_struct;
#endif // DATA_TYPES_H_INCLUDED
