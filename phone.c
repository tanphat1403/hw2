
#include<stdio.h>
#include"phone.h"
#include<stdlib.h>



phone_info_t* create_phone()
{
    phone_info_t* phone;
    phone = malloc(sizeof(phone_info_t));
    printf("Enter phone\'s code: ");
    scanf("%s", phone->code);
    fflush(stdin);

    printf("Enter phone\'s name: ");
    scanf("%s", phone->name);
    fflush(stdin);
    
    printf("Enter phone\'s price: ");
    scanf("%f", &phone->price);
    fflush(stdin);

    printf("Enter phone\'s nums: ");
    scanf("%d", &phone->nums);
    fflush(stdin);

    return phone;
}

void add_phone(linked_list_t *list)
{
    phone_info_t* phone = create_phone(phone);
    ll_node_t* p = list->head;
    if (p == NULL)
    {
        ll_add(list, phone);
        return;
    }

    while(p != NULL)
    {
        phone_info_t* curr_phone = (phone_info_t*)p->object;
        if (curr_phone->price > phone->price)
        {
            if (p == list->head)
            {
                ll_add_front(list, phone);
            }
            else
            {
                ll_add_after(list, p->prev, phone);
            }
            printf("add phone to list successful");
            return;
        }
        p = p->next;
    }
    //phone has highest price
    ll_add(list, phone);
    return;
}

void print_phone_list(linked_list_t* list)
{
    ll_node_t* p = list->head;
    
    while (p != NULL)
    {
        phone_info_t* phone = (phone_info_t*)p->object; 
        printf("[%f]->", phone->price);
        p = p->next;
    }
    printf("[]\n");
}