//
//  main.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "linked_list.h"
#include "phone.h"

int main(int argc, const char * argv[]) {
    linked_list_t* phone_list;
    phone_list = ll_create();
    //phone_info_t* phone = create_phone();
    while(1)
    {
        // system("clear");
        printf("-----------------------------\n");
        printf("1. Add phone's info\n");
        printf("2. Delete phone's info\n");
        printf("3. Change phone's nums\n");
        printf("4. Search phone\n");
        printf("5. Display all phone's info\n");

        int mode;
        printf("Choose: ");
        scanf("%d", &mode);
        fflush(stdin);
        switch(mode)
        {
            case 1:
                add_phone(phone_list);
                break;
            case 2:
                remove_phone(phone_list);
                break;
            case 3:
                change_nums(phone_list);
                break;
            case 4:
                search_phone(phone_list);
                break;
            case 5:
                print_phone_list(phone_list);
            default:
                break;
        }
    }
}
