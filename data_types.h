#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED


 typedef enum
{
    char_t,
    int_t,
    double_t,
    node_t,
    other_type
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
 typedef struct{
    element* elements;
    int cursize;
}generic_array;

typedef struct
{
    generic_array* hash_array;

}generic_hash_map;



#endif // DATA_TYPES_H_INCLUDED
