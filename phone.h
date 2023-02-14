#include"linked_list.h"

#define MAX_CODE_SIZE 50
#define MAX_NAME_SIZE 50

typedef struct phone_info
{
    char code[MAX_CODE_SIZE];
    char name[MAX_NAME_SIZE];
    float price;
    int nums;
} phone_info_t;


phone_info_t* create_phone();
void add_phone(linked_list_t *list);
void print_phone_list(linked_list_t* list);
void remove_phone(linked_list_t* list);
void change_nums(linked_list_t* list);
void search_phone(linked_list_t* list);
void print_phone_info(ll_node_t* node);


