#ifndef GENERIC_LL_H_INCLUDED
#define GENERIC_LL_H_INCLUDED

#include "data_types.h"
typedef struct llnode
{
    void* data;
    data_type_t type;
    struct llnode* next;
} node;

node* head,*tail;

void generic_ll_intialise()
{
    head=tail=NULL;
}

//insert at a particular index in the array
void generic_ll_insert_head(void* data, int data_size)
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


    temp->next=head;

    if(head==NULL)
        tail=temp;
    head=temp;

}

void generic_ll_pop_head()
{
    if(head==NULL)
        return head;
    node* temp=head;
    head=head->next;
    if(head==NULL)
        tail=NULL;
    free(temp);

}

void generic_ll_insert_tail(void* data, int data_size)
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
    if(tail!=NULL)
        tail->next=temp;
    else head=temp;
    tail=temp;

}

void* generic_ll_get_head()
{
    if(head!=NULL)
        return head->data;
    else return NULL;
}

void* generic_ll_get_tail()
{
    if(tail!=NULL)
        return tail->data;
    else return NULL;
}


void generic_ll_print()
{
    node* itr=head;
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




#endif // GENERIC_LL_H_INCLUDED
