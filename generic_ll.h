#ifndef GENERIC_LL1_H_INCLUDED
#define GENERIC_LL1_H_INCLUDED

#include "data_types.h"
typedef struct llnode
{
    void* data;
    data_type_t type;
    struct llnode* next;
} node;

void generic_ll_intialise(node** head)
{
     (*head)=NULL;
}

//insert at a particular index in the array
void generic_ll_insert_head(node** head,void* data, int data_size)
{
    node* temp=malloc(sizeof(node));
    temp->data=malloc(data_size);
    memcpy(temp->data,data,data_size);
    switch(data_size)
    {
    case sizeof(char):
        temp->type=char_t;
        break;
    case sizeof(int):
        temp->type=int_t;
        break;
    case sizeof(double):
        temp->type=double_t;
        break;
    default:
        temp->type=string_t;
    }


    temp->next=(*head);
    (*head)=temp;

}

void generic_ll_pop_head(node** head)
{
    if((*head)==NULL)
        return ;
    node* temp=(*head);
    (*head)=(*head)->next;
    free(temp);

}

void generic_ll_insert_tail(node** head,void* data, int data_size)
{
    node* temp=malloc(sizeof(node));
    temp->data=malloc(data_size);
    memcpy(temp->data,data,data_size);

    switch(data_size)
    {
    case sizeof(char):
        temp->type=char_t;
        break;
    case sizeof(int):
        temp->type=int_t;
        break;
    case sizeof(double):
        temp->type=double_t;
        break;
    default:
        temp->type=string_t;
    }

    node* tail=(*head);
    if(tail==NULL)
    {
        (*head)=temp;
        return;
    }
    else
    {
        while(tail->next)
        {
            tail=tail->next;
        }
        tail->next=temp;
    }

}

void* generic_ll_get_head(node** head)
{
    if((*head)!=NULL)
        return (*head)->data;
    else return NULL;
}



void generic_ll_print(node** head)
{
    node* itr=(*head);
    while(itr)
    {

        switch(itr->type)
        {
        case char_t :
            printf("%c\n",*(char*)(itr->data));
            break;
        case int_t :
            printf("%d\n",*(int*)itr->data);
            break;
        case double_t :
            printf("%f\n",*(double*)itr->data);
            break;
        case string_t:
            printf("%s\n",(char*)itr->data);
            break;

        }
        itr=itr->next;
    }
}




#endif // GENERIC_LL1_H_INCLUDED
