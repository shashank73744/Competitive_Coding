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
    struct linked_list *next,*previous;
};

struct linked_list *head , * tail;

struct linked_list * getNode(){
    linked_list * node = (linked_list *) (malloc(sizeof(struct linked_list)));
    node->previous = NULL;
    node->value = -1;
    return node;
}

void destroyQueue(){
    linked_list *temp;
    while(tail!=NULL){
        temp = tail;
        tail=tail->previous;
        free(temp);
    }
}

void push(int val){
    struct linked_list *newHead = getNode();
    newHead->value = val;
    if(head != NULL)head->previous = newHead;
    if(tail == NULL)tail = newHead;
    head = newHead;
    return;
}

int pop(){
    int val = tail->value;
    linked_list *tail1 = tail;
    if(tail != NULL){
        tail = tail->previous;
        free(tail1);
    }
    return val;
}

int main() {
    int T,n;
    char val;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    head = NULL;
    tail = NULL;
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
    destroyQueue();
    return 0;
}
