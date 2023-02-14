
#include<stdio.h>
#include"phone.h"
#include<stdlib.h>
#include<string.h>



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
            return;
        }
        p = p->next;
    }
    //phone has highest price
    ll_add(list, phone);
    return;
}

void remove_phone(linked_list_t* list)
{
    if (is_empty(list))
    {
        printf("phone_list is empty");
        return;
    }
    char code[MAX_CODE_SIZE];

    printf("Enter phone\'s code you want to remove: ");
    scanf("%s", code);
    fflush(stdin);

    ll_node_t* p = list->head;
    while (p != NULL)
    {
        phone_info_t* curr_phone = (phone_info_t*)p->object;
        if (!strncmp(curr_phone->code, code, MAX_CODE_SIZE))
        {
            free(p->object);
            ll_remove(list, p);
            return;
        }
        p = p->next;
    }
    printf("Code not found");
    return;
}

void change_nums(linked_list_t* list)
{
    if (is_empty(list))
    {
        printf("phone_list is empty");
        return;
    }
    char code[MAX_CODE_SIZE];

    printf("Enter phone\'s code you want to change nums: ");
    scanf("%s", code);
    fflush(stdin);

    ll_node_t* p = list->head;
    while (p != NULL)
    {
        phone_info_t* curr_phone = (phone_info_t*)p->object;
        if (!strncmp(curr_phone->code, code, MAX_CODE_SIZE))
        {
            printf("Enter new nums: ");
            scanf("%d", &curr_phone->nums);
            fflush(stdin);
            return;
        }
        p = p->next;
    }
    printf("Code not found");
    return;
}


void search_phone(linked_list_t* list)
{
    if (is_empty(list))
    {
        printf("phone_list is empty");
        return;
    }
    float price;
    printf("Enter price to search: ");
    scanf("%f", &price);
    printf("--------------------------\n");
    fflush(stdin);

    ll_node_t* p = list->head;
    ll_node_t* approximate_node = NULL;
    ll_node_t* upper_approximate_node = NULL;
    ll_node_t* lower_approximate_node = NULL;

    while (p != NULL)
    {
        phone_info_t* curr_phone = (phone_info_t*)p->object;
        ll_node_t* prev_node = p->prev;
        ll_node_t* next_node = p->next;

        if (curr_phone->price > price && p == list->head)
        {
            approximate_node = p;
            upper_approximate_node = p->next;
            lower_approximate_node = p->prev;
            break;
        }
        
        if (curr_phone->price > price)
        {
            phone_info_t* prev_phone = (phone_info_t*)prev_node->object;
            if (curr_phone->price - price > price - prev_phone->price)
            {
                approximate_node = prev_node;
            }
            else 
            {
                approximate_node = p;
            }
            upper_approximate_node = approximate_node->next;
            lower_approximate_node = approximate_node->prev;
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        approximate_node = list->tail;
        upper_approximate_node = approximate_node->next;
        lower_approximate_node = approximate_node->prev;
    }

    printf("Lower phone:       ");
    print_phone_info(lower_approximate_node);
    printf("Approximate phone: ");
    print_phone_info(approximate_node);
    printf("Upper phone:       ");
    print_phone_info(upper_approximate_node);
}


void print_phone_info(ll_node_t* node)
{
    if (node == NULL)
    {
        printf("None\n");
        return;
    }
    phone_info_t* phone = (phone_info_t*)node->object;
    printf("Name: %s\tPrice: %.3f\n", phone->name, phone->price);
}

void print_phone_list(linked_list_t* list)
{
    ll_node_t* p = list->head;
    
    while (p != NULL)
    {
        print_phone_info(p);
        p = p->next;
    }
}

