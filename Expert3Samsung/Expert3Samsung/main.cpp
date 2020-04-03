//
//  main.cpp
//  Expert3Samsung
//
//  Created by Shashank Saurabh on 3/5/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <stdio.h>
//.rawInput

using namespace std;

struct car{
    
    int age;
    int passenger;
    int engine;
    int price;
    car * next;
    car * back;
    car * up;
    car * down;
    
};

struct car *start, *skipList[30],*next_st[30], *prev_st[30], *f , *t,*selling[1000000];
int flag,debug,sell_counter;

int cmp(car *a, car *b){
    if(a->age > b->age) return 1;
    else if(a->age < b->age) return -1;
    else{
        if(a->passenger > b->passenger) return 1;
        else if(a->passenger < b->passenger) return -1;
        else{
            if(a->engine > b->engine) return 1;
            else if(a->engine < b->engine) return -1;
            else{                 if(a->price > b->price) return 1;
                else if(a->price < b->price) return -1;
                else{
                    return 0;
                }
            }
        }
    }
}

struct car * createNegativeInfinite(){
    struct car * pointer = (struct car*) malloc (1*sizeof(car));
    pointer->age = -1;
    pointer->passenger = -1;
    pointer->engine = -1;
    pointer->price = -1;
    pointer->next = NULL;
    pointer->back = NULL;
    pointer->up = NULL;
    pointer->down = NULL;
    return pointer;
}

void position_find (struct car *a){
    struct car *next = start->next, *prev = start;
    for(int i =0;i<30;i++){
        if(debug == 1){
            cout<<a->age<<'\t'<<prev->age<<endl;
        }
        while(next != NULL && cmp(next,a)==-1 ){
            prev = next;
            next = next->next;
        }
        next_st[i] = next;
        prev_st[i] = prev;
        prev = prev->down;
        if(prev != NULL)next = prev->next;
    }
}

void add_level (struct car * current , struct car * down ,int counter){
    prev_st[counter]->next = current;
    if(next_st[counter] != NULL)next_st[counter]->back = current;
    current->next = next_st[counter];
    current->back = prev_st[counter];
    current->up = NULL;
    current->down = down;
    current->age = down->age;
    current->engine = down->engine;
    current->price = down->price;
    current->passenger = down->passenger;
    down->up = current;
}

void print_list(){
    struct car *start;
    for(int i=0;i<30;i++){
        start = skipList[i]->next;
        cout<<"Level-> "<<i<<'\t';
        while(start != NULL){
            cout<<"("<<start->age<<","<<start->passenger<<","<<start->engine<<","<<start->price<<","<<")"<<'\t';
            //cout<<start->age<<'\t';
            start = start->next;
        }
        cout<<endl;
    }
}

void buy(struct car *a ){
    
    int counter = 28;
    struct car *down , *current;
    if(flag != 109765){
        skipList[0] = createNegativeInfinite();
        start = skipList[0];
        for(int i=1;i<30;i++){
            skipList[i] = createNegativeInfinite();
            skipList[i-1]->down = skipList[i];
            skipList[i]->up = skipList[i-1];
        }
        flag = 109765;
    }
    position_find(a);
    prev_st[29]->next = a;
    if(next_st[29]!= NULL)next_st[29]->back = a;
    a->next = next_st[29];
    a->back = prev_st[29];
    a->up = NULL;
    a->down = NULL;
    down = a;
    while(rand()%2==0 && counter>=0){
        current = (struct car *)malloc(sizeof(struct car));
        add_level(current,down,counter);
        down = current;
        --counter;
    }
    if (debug == 2) {
        print_list();
        cout<<endl<<"------------------------------------------------------------------------------"<<endl;
    }
}

void filterByAge(int from , int to){
    f->age=from;
    t->age=to;
}

void filterByPassenger(int from , int to){
    f->passenger=from;
    t->passenger=to;
}

void filterByEngine(int from , int to){
    f->engine=from;
    t->engine=to;
}

void filterByPrice(int from , int to){
    f->price=from;
    t->price=to;
}

int sell(){
    struct car *to[30] , *from[30],*start_ ,*end_,*temp;
    if (cmp(f,t)==1){
        temp =f;
        f=t;
        t=temp;
    }
    position_find(f);
    if(debug == 3){
        cout<<f->age<<'\t'<<t->age<<endl;
        print_list();
        cout<<"---------------------------------------------------------------------------------------";
    }
    for(int i =0 ;i<30;i++){
        from[i] = prev_st[i];
    }
    position_find(t);
    for(int i =0 ;i<30;i++){
        to[i] = next_st[i];
    }
    for(int i=0;i<29;i++){
        start_= from[i]->next;
        end_ = to[i];
        while(start_ !=end_){
            temp = start_;
            start_ = start_->next;
            free(temp);
        }
        from[i]->next = to[i];
        if(to[i]!=NULL)to[i]->back = from[i];
    }
    ++ sell_counter;
    if(from[29]->next != to[29])
    selling[sell_counter]=from[29]->next;
    else
        selling[sell_counter]=NULL;
    from[29]->next = to[29];
    if(to[29]!=NULL && to[29]->back!=NULL && to[29]->back!=from[29])to[29]->back->next = NULL;
    if(to[29]!=NULL)to[29]->back = from[29];
    if(debug == 3){
        print_list();
        cout<<"---------------------------------------------------------------------------------------";
    }
    if(debug == 5){
        cout<<sell_counter<<endl;
    }
    return sell_counter;
}

int empty(){
    struct car * starting,*next;
    int counter =0 ;
    for(int i =0 ;i<29;i++){
        starting = skipList[i]->next;
        while(starting !=NULL){
            next = starting->next;
            free(starting);
            starting =next;
        }
        skipList[i]->next = NULL;
    }
    starting = skipList[29]->next;
    while(starting !=NULL){
        next = starting->next;
        free(starting);
        starting =next;
        ++counter;
    }
    skipList[29]->next =NULL;
    return counter;
}

void refund(int order_number){
    struct car *starting, * next;
    starting = selling[order_number];
    selling[order_number] = NULL;
    if(debug == 5){
        cout<<"Refund"<<order_number<<endl;
    }
    while(starting!=NULL){
        next = starting->next;
        if(debug == 4){
            cout<<"***********************************************"<<endl;
            cout<<starting->age<<" "<<'\t';
            cout<<"***********************************************"<<endl;
            print_list();
            cout<<"---------------------------------------------------------------------------------------";
        }
//        pointer->age = starting->age;
//        pointer->passenger = starting->passenger;
//        pointer->engine = starting->engine;
//        pointer->price = starting->price;
        starting->next = NULL;
        starting->back = NULL;
        starting->up= NULL;
        starting->down = NULL;
        buy(starting);
        starting = next;
    }
    
}

int main(){
int order_number, o;
    debug =0;
freopen("/Users/shashanksaurabh/Desktop/Journey/Expert3Samsung/Expert3Samsung/ans.txt", "w", stdout);
f=(struct car *)malloc(sizeof(struct car));
t=(struct car *)malloc(sizeof(struct car));
for(int j = 0 ; j<10;j++){
    srand (1);
    order_number = -1;
    sell_counter = -1;
    for (int i = 0 ; i<1000000; i++){
        struct car *a;
        a=(struct car *)malloc(sizeof(struct car));
        a->age = rand()%20;
        a->passenger = rand()%20;
        a->engine = rand()%4000;
        a->price = rand()%40000;
        buy(a);
        if(rand()%1000 == 0){
            filterByAge(rand()%20 ,rand()%20);
            filterByPassenger(rand()%20 ,rand()%20);
            filterByEngine(rand()%4000 ,rand()%4000);
            filterByPrice(rand()%40000 ,rand()%40000);
            o = sell();
            if(rand()%10 == 0){
                order_number = o;
            }
        }
        if(rand()%10000 == 0){
            if(order_number != -1){
                refund(order_number);
            }
        }
    }
    cout<<empty()<<endl;
    //print_list();
    }
    return 0;
}

    
