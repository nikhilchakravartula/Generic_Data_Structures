#ifndef GENERIC_ARRAY_H_INCLUDED
#define GENERIC_ARRAY_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include "generic_ll.h"
#include "data_types.h"



void* generic_array_intialise(unsigned n,data_type_t type)
{
    generic_array* arr=malloc(sizeof(generic_array));
    arr->elements=malloc(sizeof(element)*n);
    arr->cursize=0;
    for(int i=0; i<n; i++)
    {
        arr->elements[i].data=NULL;
        arr->elements[i].type=other_t;
    }
    return arr;
}

//insert at a particular  in the array
void generic_array_insert(void* arr,void* data, int index, data_type_t type,int data_size)
{
    generic_array* garr=(generic_array*)arr;
    if(type!=node_t)
    {
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
    }
    else
    {
        //printf("index=%d",index);
        if((garr)->elements[index].data==NULL)
        {

            //(garr)->elements[index].data=malloc(get_size(type));
            generic_ll_intialise(  &((garr)->elements[index].data)  );
        }

        generic_ll_insert_head(  (node**)&((garr)->elements[index].data ),data, data_size);

    }
    (garr)->elements[index].type=type;
    (garr)->cursize++;


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
    case node_t:
        return sizeof(node);
    }

}

void generic_array_print(void* arr,data_type_t type)
{
    generic_array* garr=(generic_array*)arr;
    if(type!=node_t)
    {
        for(int i=0; i<garr->cursize; i++)
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


            }

        }
    }
    else
    {
        node* ptr;
        for(int i=0; i<1007; i++)
        {
            ptr=(node*)garr->elements[i].data;
            if(ptr!=NULL && ptr->data!=NULL)
            {
                printf("i=%d\t",i);
                generic_ll_print(&ptr);
                printf("\n");
            }
        }
    }
}

void generic_array_remove_index(generic_array* arr,int index,data_type_t type,int data_size)
{
    generic_array* garr=(generic_array*)arr;
    if(index>=garr->cursize)
        return;
    if(type!=node_t)
    {
        while(index+1 !=garr->cursize)
        {
            // printf("\n\n%s\n\n",garr->elements[temp]) ;
            garr->elements[index].data=malloc(get_size(garr->elements[index+1].type));
            memcpy(garr->elements[index].data,garr->elements[index+1].data,get_size(garr->elements[index].type));
            garr->elements[index].type=garr->elements[index+1].type;
            index++;
        }
        (garr)->cursize--;
    }



}

/*
void generic_array_remove_data(generic_array* arr,void* data,data_type_t type)
{
    switch(type)
    {
        case char_t:

    }
}
*/


#endif // GENERIC_ARRAY1_H_INCLUDED
