#ifndef GENERIC_LL_H_INCLUDED
#define GENERIC_LL_H_INCLUDED

#include "data_types.h"

void generic_ll_intialise(node** head)
{

    //(*head)=NULL;
    (*head)=malloc(sizeof(node));
    (*head)->data=NULL;
    (*head)->next=NULL;
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
    }


    temp->next=(*head);
    (*head)=temp;
}

void generic_ll_pop_head(node** head)
{
    if( (*head)->data==NULL)
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
    }

    node* tail=(*head);
    if(tail->data==NULL)
    {
        temp->next=(*head);
        (*head)=temp;
        return;
    }
    else
    {
        node* prev=tail;
        while(tail->data)
        {
            prev=tail;
            tail=tail->next;
        }

        prev->next=temp;
        temp->next=tail;

    }

}

void* generic_ll_get_head(node** head)
{
    return (*head)->data;
}



void generic_ll_print(node** head)
{
    node* itr=(*head);
    while(itr->data)
    {

        switch(itr->type)
        {
        case char_t :
            printf("%c\t",*(char*)(itr->data));
            break;
        case int_t :
            printf("%d\t",*(int*)itr->data);
            break;
        case double_t :
            printf("%f\t",*(double*)itr->data);
            break;

        }
        itr=itr->next;
    }
}

bool generic_ll_present(node** head,void* data,data_type_t type)
{
     node* ptr=(*head);


    switch(type)
    {

    case char_t:

        ;
        char char_value=get_char(data);

        while(ptr && ptr->data)
        {

            if(ptr->type==char_t)
            {
                if(char_value== get_char(ptr->data))
                {

                   return true;
                }
            }
            ptr=ptr->next;
        }

        break;
    case int_t:
        ;
        int int_value=get_int(data);
        while(ptr && ptr->data)
        {

            if(ptr->type==int_t)
            {
                if(int_value== get_int(ptr->data))
                {
                   return true;
                }
            }

            ptr=ptr->next;
        }
        break;
    case double_t:
        ;
        double double_value=get_double(data);
        while(ptr && ptr->data)
        {

            if(ptr->type==double_t)
            {
                if(double_value== get_double(ptr->data))
                {
                    return true;
                }
            }

            ptr=ptr->next;
        }
        break;

    }
    return false;

}
void generic_ll_remove(node** head,void* data,data_type_t type)
{
    node* ptr=(*head);
    node* prev=NULL;
    node* temp;

    switch(type)
    {

    case char_t:

        ;
        char char_value=get_char(data);

        while(ptr && ptr->data)
        {

            if(ptr->type==char_t)
            {
                if(char_value== get_char(ptr->data))
                {
                    if(prev==NULL)
                    {
                        (*head)=(*head)->next;
                        free(ptr);
                        return;
                    }
                    prev->next=ptr->next;
                    free(ptr);
                    break;
                }
            }
            prev=ptr;
            ptr=ptr->next;
        }
        break;
    case int_t:
        ;
        int int_value=get_int(data);
        while(ptr && ptr->data)
        {

            if(ptr->type==int_t)
            {
                if(int_value== get_int(ptr->data))
                {
                    if(prev==NULL)
                    {
                        (*head)=(*head)->next;
                        free(ptr);
                        return;
                    }
                    prev->next=ptr->next;
                    free(ptr);
                    break;
                }
            }
            prev=ptr;
            ptr=ptr->next;
        }
        break;
    case double_t:
        ;
        double double_value=get_double(data);
        while(ptr && ptr->data)
        {

            if(ptr->type==double_t)
            {
                if(double_value== get_double(ptr->data))
                {
                    if(prev==NULL)
                    {
                        (*head)=(*head)->next;
                        free(ptr);
                        return;
                    }
                    prev->next=ptr->next;
                    free(ptr);
                    break;
                }
            }
            prev=ptr;
            ptr=ptr->next;
        }
        break;

    }
}


#endif // GENERIC_LL1_H_INCLUDED
