// C++ implementation of search and insert
// operations on Trie
#include <stdio.h>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct Trienode {
    struct Trienode *children[ALPHABET_SIZE];
    bool Endofword;
    int count;
};

struct Trienode* getNode(void){
    struct Trienode *node = new Trienode;
    node->Endofword = false;
    node->count = 0;
    for (int i=0; i<ALPHABET_SIZE; i++)
        node->children[i]= NULL;
    return node;
}

void Insert(Trienode *root,string key){
    struct Trienode *pCrawl = root;
    int index;
    for (int i=0; i<key.length(); i++) {
        index = key.at(i)-'A';
        pCrawl->count +=1;
        if(!pCrawl->children[index])
            pCrawl->children[index]=getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->Endofword = true;
    pCrawl->count = 1;
    
}

int main()
{
    freopen("/Users/shashanksaurabh/Desktop/Journey/Whole_word_2/Whole_word_2/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Whole_word_2/Whole_word_2/output.txt", "w", stdout);
    int N,L,pos,T;
    long long pmc[1001];
    bool alphabet[26],found=false;
    cin>>T;
    for (int testCase=1; testCase<=T; ++testCase) {
        cin>>N>>L;
        found=false;
        string *keys = new string[N];
        for (int i=0; i<N; i++) {
            cin>>keys[i];
        }
        for (int i=L-1; i>=0; i--) {
            pmc[i]=0;
            for (int i=0; i<26; i++) {
                alphabet[i]=false;
            }
            for (int j=0; j<N; j++) {
                if(!alphabet[keys[j].at(i)-'A']){
                    alphabet[keys[j].at(i)-'A'] = true;
                    ++pmc[i];
                }
            }
            if(i<L-1)pmc[i]=(pmc[i]*pmc[i+1]);
        }
        pmc[L]=1;
        struct Trienode *root = getNode(),*pCrawl;
        for (int i = 0; i < N; i++)
            Insert(root, keys[i]);
        cout<<"Case #"<<testCase<<": ";
        if(root->count < pmc[0]){
            pCrawl=root;
            for (int i=0; i<L; i++) {
                if(found){
                    cout<<keys[0].at(i);
                }
                else{
                    for (int j=0; j<N; j++) {
                        pos = keys[j].at(i) - 'A';
                        if(!pCrawl->children[pos]){
                            found=true;
                            cout<<keys[j].at(i);
                            break;
                        }
                        else if(pCrawl->children[pos]->count <pmc[i+1]){
                            cout<<keys[j].at(i);
                            pCrawl = pCrawl->children[pos];
                            break;
                        }
                    }
                }
            }
        }
        else{
            cout<<"-";
        }
        cout<<endl;
    }
    return 0;
}
