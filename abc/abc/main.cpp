//
//  main.cpp
//  abc
//
//  Created by Shashank Saurabh on 7/14/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


vector <int> get_ranks(vector <string> words) {
    vector <int> arr[];
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    vector <int> res;
    int words_size = 0;
    cin >> words_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    vector<string> words;
    for(int i = 0; i < words_size; i++) {
        string words_item;
        getline(cin, words_item);
        words.push_back(words_item);
    }
    
    res = get_ranks(words);
    for(int res_i = 0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}


int permutation(string str){
    int alphabet[26][2],counter=0,index;
    string str2;
    strcpy(str2,str);
    sort(str2.start(),str2.end());
    for(int i=0;i<26;i++){
        alphabet[i][0]=0;
    }
    
    for(int i=0;i<str2.length();i++){
        index = str2[i]-'a';
        alphabet[index][1]=counter;
        ++counter;
    }
    
    for(int i=0;i<str.length();i++){
        
    }
    
} 
