//
//  main.cpp
//  Stack
//
//  Created by Shashank Saurabh on 7/24/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include "edx-io.hpp"

using namespace std;

struct linked_list{
    int value;
    struct linked_list *next;
};

struct linked_list *head;

struct linked_list * getNode(){
    linked_list * node = new linked_list;
    node->next = NULL;
    return node;
}

void push(int val){
    struct linked_list *newHead = getNode();
    newHead->value = val;
    newHead->next = head;
    head = newHead;
    return;
}

int pop(){
    int val = head->value;
    linked_list *head1 = head;
    head = head->next;
    free (head1);
    return val;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T,n;
    char val;
    head = getNode();
    io>>T;
    for (int i=0; i<T; i++) {
        io>>val;
        if(val=='+'){
            io>>n;
            push(n);
        }
        else if(val == '-')
            io<<pop()<<'\n';
    }
    return 0;
}
