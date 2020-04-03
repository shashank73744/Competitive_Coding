// C++ implementation of search and insert
// operations on Trie
#include <stdio.h>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;
const int MAX_SIZE = 3000;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int count;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    pNode->count=0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key,bool add)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';
        if(add)pCrawl->count+=1;
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->count=1;
    pCrawl->isEndOfWord = true;
}

int main()
{
    freopen("/Users/shashanksaurabh/Desktop/Journey/New_Word/New_Word/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/New_Word/New_Word/output.txt", "w", stdout);
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
    struct TrieNode *root = getNode(),*pCrawl;
    for (int i = 0; i < N; i++)
        insert(root, keys[i],true);
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
