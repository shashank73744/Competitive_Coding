#include<stdio.h>
#include<iostream>

using namespace std;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

void update(int *st, int n, int pos, int val) {
    pos += n;
    st[pos] = val;
    for (; pos>1; pos >>= 1) {
        st[pos>>1] = st[pos] + st[pos ^ 1];
    }
}

int querry(int *st, int n, int l, int r) {
    int ans = 0;
    if (l <= r && r >= 0)ans = st[r + n];
    for (l += n, r += n; l<r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ans += st[l++];
        }
        if (r & 1) {
            ans += st[--r];
        }
        
    }
    return ans;
}

int binarySearch(int *st, int n, int val, int s, int e) {
    if (s == e ) {
        return s;
    }
    int mid = getMid(s, e);
    int res = querry(st, n, 0, mid);
    if (val<=res) {
        return binarySearch(st, n, val, s, mid);
    }
    else {
        return binarySearch(st, n, val, mid + 1, e);
    }
}

int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Dr.Misha and Permutation/Dr.Misha and Permutation/input.txt","r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Dr.Misha and Permutation/Dr.Misha and Permutation/output.txt","w",stdout);
    int v, n, add = 0, carry = 0;
    cin >> n;
    int *st1 = new int[2 * n];
    int *st2 = new int[2 * n];
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *res = new int[n];
    for (int i = 0; i<n; i++)cin >> arr1[i];
    for (int i = 0; i<n; i++)cin >> arr2[i];
    for (int i = 0; i<2 * n; i++) { st1[i] = 0; st2[i] = 0; }
    for (int i = 0; i<n; i++) {
        update(st1, n, arr1[n - i - 1], 1);
        update(st2, n, arr2[n - i - 1], 1);
        add = querry(st1, n, 0, arr1[n - i - 1]) + querry(st2, n, 0, arr2[n - i - 1]) + carry-2;
        carry = add / (i + 1);
        res[n - i - 1] = add % (i + 1);
    }
    //for (int i=0; i<n; i++) {
        //cout<<res[i]<<" ";
    //}
    //cout<<endl;
    for (int i = 0; i<n; i++) {
        v = binarySearch(st1, n, res[i] + 1, 0, n - 1);
        update(st1, n, v, 0);
        cout << v << " ";
    }
    cout << endl;
    return 0;
}