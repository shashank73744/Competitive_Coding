//
//  main.cpp
//  Queue_with_minimum
//
//  Created by Shashank Saurabh on 7/28/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;

struct stackNode *headStack;
struct queueNode *headQueue, *tailQueue;

struct stackNode{
    struct stackNode *next;
    int val;
};

struct queueNode{
    struct queueNode *previous;
    int val;
};

struct queueNode* getQueueNode(){
    struct queueNode* node;
    node = new queueNode;
    node->previous = NULL;
    node->val = -1;
    return node;
}

struct stackNode* getStackNode(){
    struct stackNode *node;
    node = new stackNode;
    node->next = NULL;
    return node;
}

void pushStack(int val){
    struct stackNode *node;
    node = getStackNode();
    node->val = val;
    node->next = headStack;
    headStack = node;
}

int popStack(){
    int val = headStack->val;
    headStack = headStack->next;
    return val;
}

int querryStack(){
    return headStack->val;
}

int min_c(int a, int b){
    return a<b?a:b;
}

void pushQueue(int val){
    struct queueNode *node;
    node = new queueNode;
    node->val = val;
    if(headQueue != NULL)headQueue->previous = node;
    if(tailQueue == NULL) tailQueue = node;
    headQueue = node;
}

int popQueue(){
    int val = tailQueue->val;
    tailQueue = tailQueue->previous;
    return val;
}

int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Queue_with_minimum/Queue_with_minimum/input.txt","r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Queue_with_minimum/Queue_with_minimum/output", "w", stdout);
    int T,value;
    char op;
    cin>>T;
    headStack = NULL;
    headQueue = NULL;
    tailQueue = NULL;
    pushStack(1000000001);
    for (int i = 0; i<T; i++) {
        cin>>op;
        if(op == '+'){
            cin>>value;
            pushQueue(value);
            pushStack(min_c(value,querryStack()));
        }
        else if(op == '-'){
            popQueue();
            popStack();
        
        }
        else if(op == '?'){
            cout<<querryStack()<<endl;
        }
    }
    
    return 0;
}
