#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
long long minimum,m,w,p,n;
double c;
long min_pre(long nu, long steps){
    long ca = c - nu*p;
    if (m < w){ long temp; temp = m; m = w; w = temp; }
    if (m - w >= nu) return ceil(((double)(n - ca) / m)/(w + nu)) + steps;
    else{
        long a = (nu - m + w) / 2; long b = nu - m + w - a;
        return ceil(((double)(n - ca) / (m + a))/(m + b)) + steps;
    }
    
}

void update(long nu){
    c=c-nu*p;
    if (m < w){ long temp; temp = m; m = w; w = temp; }
    if (m - w >= nu) {w = w + nu; return;}
    else{
        long a = (nu - m + w) / 2; long b = nu - m + w - a;
        w = m + a; m = m + b;
        return;
    }
    
}

void binarySearch(long start , long end,long steps){
    if (start > end) return;
    long mid = (start + end) / 2;
    long value = min_pre(mid,steps);
    minimum = value < minimum ? value : minimum;
    if (value < min_pre(end, steps)) binarySearch( mid +1,  end,  steps);
    else binarySearch(start, mid-1, steps);
}

void search(long steps){
    //cout<<m<<"\t"<<w<<"\t"<<c<<"\t"<<steps<<endl;
    if (steps >= minimum) return;
    long total_buy = c / p;
    binarySearch(0, total_buy, steps);
    if(total_buy > 0){
        update(total_buy);
        c = c + (double)m*w;
        search(steps + 1);
    }
    else{
        long aux_steps =ceil((double)(p-c)/((double)m*w));
        c=c+aux_steps*m*w;
        search(steps + aux_steps);
    }
    
    
    
}
int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Expert/Expert/input.txt", "r", stdin);
    //freopen("/Users/shashanksaurabh/Desktop/Journey/Expert/Expert/ans.txt", "w", stdout);
    c = 0;
    minimum = 1000000000000;
    cin >> m >> w >> p >> n;
    search(0);
    cout << minimum;
    return 0;
}
