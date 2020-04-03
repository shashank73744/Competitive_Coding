#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int main(){
    freopen("/Users/shashanksaurabh/Desktop/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/output.txt", "w", stdout);
    int t,s1,e1,s2,e2,N;
    string l1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>N;
        cin>>l1;
        s1=0;e1=0;s2=0;e2=0;
        cout<<"Case #"<<i<<": ";
        for(int j=0;j<2*N -2;j++){
            if(s1==s2 && e1==e2){
                if(l1[j] == 'S'){
                    cout<<'E';
                    ++e2;
                }
                else{
                    cout<<'S';
                    ++s2;
                }
            }
            else if(s2==e2){
                if(l1[j] == 'S'){
                    cout<<'S';
                    ++s2;
                }
                else{
                    cout<<'E';
                    ++e2;
                }
            
            }
            else if (s2 == e2+1){
                cout<<'E';
                ++e2;
                
            }
            else if(s2 == e2 -1){
                cout<<'S';
                ++s2;
            }
            if(l1[j] == 'S')++s1;
            if(l1[j] == 'E')++e1;
            
        }
        cout<<endl;
        
    }
    
}