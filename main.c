#include <stdio.h>
#include <stdlib.h>
#include "generic_array1.h"
#include "generic_ll1.h"
#include "data_types.h"
void test_generic_array()
{
    printf("\nTESTING GENERIC ARRAY\n");
    void* arr=generic_array_intialise(100,int_t);
    char ch='A';
    for(int i=0; i<4; i++)
    {
        printf("here\n");
        generic_array_insert(arr,&ch,i,sizeof(ch));
        ch++;
    }

    int t=5;
    for(int i=0; i<5; i++)
    {
        generic_array_insert(arr,&t,i,sizeof(t));
        t++;
    }
    generic_array_insert(arr,&ch,2,sizeof(ch));

    double d=5.6;
    for(int i=2; i<4; i++)
    {
        generic_array_insert(arr,&d,i,sizeof(d));
        d++;
    }

    generic_array_print(arr);

}
void test_generic_ll()
{
    printf("\nTESTING GENERIC LINKED LIST\n");
    node* head;
    generic_ll_intialise(&head);
    char ch='A';
    for(int i=0; i<4; i++)
    {
        generic_ll_insert_head(&head,&ch,sizeof(ch));
        ch++;
    }

    int t=5;
    for(int i=0; i<5; i++)
    {
        generic_ll_insert_head(&head,&t,sizeof(t));
        t++;
    }
    generic_ll_insert_tail(&head,&ch,sizeof(ch));

    double d=5.6;
    for(int i=2; i<4; i++)
    {
        generic_ll_insert_tail(&head,&d,sizeof(d));
        d++;
    }
    generic_ll_pop_head(&head);
    generic_ll_pop_head(&head);
    generic_ll_pop_head(&head);
    generic_ll_print(&head);

}

int main()
{
    test_generic_ll();
    return 0;
}
