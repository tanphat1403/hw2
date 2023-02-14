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
    add_phone(phone_list);
    add_phone(phone_list);
    print_phone_list(phone_list);
}
