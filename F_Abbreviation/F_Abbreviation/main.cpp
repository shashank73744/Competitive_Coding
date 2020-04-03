//
//  main.cpp
//  F_Abbreviation
//
//  Created by Shashank Saurabh on 7/13/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;

#define HASHARRAYSIZE 997

int wH[HASHARRAYSIZE],pointer;
int maxSave;
int wordsMatching[300][2];
using namespace std;
const int ALPHABET_SIZE = 997;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int iteration;
    int save;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    pNode->iteration = 0;
    pNode->save = 0;
    return pNode;
}

void insert(struct TrieNode *root, int pos , int n)
{
    struct TrieNode *pCrawl = root;
    int save =-1;
    int counter = 0;
    for (int i = pos; i < n; i++)
    {
        int index = wordsMatching[i][0];
        ++pCrawl->iteration;
        pCrawl->save = save*pCrawl->iteration;
        if(pCrawl->iteration>1){
            maxSave = maxSave > pCrawl->save ? maxSave : pCrawl->save;
        }
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
        save+=wordsMatching[i][1];
        ++counter;
    }
        pCrawl->isEndOfWord = true;
}

int HF(char word[100000],int start){
 int hash=0,i;
 for (i=start; i<100000 && word[i]!='\0'; i++) {
    hash = ((hash << 5) + hash) + word[i];
 }
    word[i] = ' ';
 pointer = i+1;
 return hash%HASHARRAYSIZE;;
};

bool cmp(char word[100000], int start1,int start2){
    while (word[start1] !=' '  && word[start2] !=' ')
    {
        if(word[start1] != word[start2] )return false;
        ++start1;
        ++start2;
    }
    return true;
}

int insert(char word[100000],int start){
    int hash = HF(word,start);
    while (wH[hash]!=-1 && !cmp(word,start,wH[hash])) {
        hash++;
    }
    if(wH[hash] == -1)wH[hash] = start;
    return wH[hash];
}



int main(int argc, const char * argv[]){
    freopen("/Users/shashanksaurabh/Desktop/Journey/F_Abbreviation/F_Abbreviation/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/F_Abbreviation/F_Abbreviation/output.txt", "w", stdout);
    int n,lengthOfString = -1;
    maxSave = 0;
    char words[100000];
    TrieNode *root = getNode();
    cin>>n;
    pointer = 0;
    for (int i=0; i<HASHARRAYSIZE; i++){
        wH[i] = -1;
    }
    for (int i=0; i<n ; i++){
        cin>>(words+pointer);
        wordsMatching[i][1] = pointer;
        wordsMatching[i][0] = insert(words,pointer);
        wordsMatching[i][1] = pointer - wordsMatching[i][1] -1 ;
        lengthOfString += wordsMatching[i][1] +1;
    }
    for (int i = 0; i<n; i++) {
        insert(root,i,n);
    }
    cout<<(lengthOfString-maxSave);
    return 0;
}
