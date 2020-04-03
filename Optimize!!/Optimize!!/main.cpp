#include <bits/stdc++.h>
#define PII pair<int, int>
#define mp make_pair
using namespace std;

const int INF = 1e9+7;
const int N = 1.5e5+7;
int tr[4*N], lz[4*N];
int a[N], b[N], l[N];
int n, k, s;

void build(int u, int st, int en)
{
    if(st==en) tr[u] = -(k+1-st);
    else {
        int mid = (st+en)>>1;
        build(u<<1, st, mid);
        build((u<<1)^1, mid+1, en);
        tr[u] = min(tr[u<<1], tr[(u<<1)^1]);
    }
}

void propogate(int u, int st, int en)
{
    tr[u] += lz[u];
    if (st!=en)     lz[u<<1]+=lz[u], lz[(u<<1)^1]+=lz[u];
    lz[u] = 0;
}

void update(int u, int st, int en, int l, int r, int inc) {
    if (lz[u])      propogate(u, st, en);
    if (st>r || en<l)   return;
    else if (l<=st && en<=r)    lz[u] = inc, propogate(u, st, en);
    else {
        int mid = (st+en)>>1;
        update(u<<1, st, mid, l, r, inc);
        update((u<<1)^1, mid+1, en, l, r, inc);
        tr[u] = min(tr[u<<1], tr[(u<<1)^1]);
    }
}

int query(int u, int st, int en, int l, int r)
{
    if (lz[u])      propogate(u, st, en);
    if (l>en || r<st)   return INF;
    else if (l<= st && en<=r)   return tr[u];
    else {
        int mid = (st+en)>>1;
        int left = query(u<<1, st, mid, l, r);
        int right = query((u<<1)^1, mid+1, en, l, r);
        return min(left, right);
    }
}

void print(int u, int st, int en)
{
    cout<<"---"<<u<<" "<<st<<" "<<en<<" "<<tr[u]<<" "<<lz[u]<<endl;
    if (st == en)   return;
    int mid = (st+en)>>1;
    print(u<<1, st, mid);
    print((u<<1)^1, mid+1, en);
}

int main()
{
    scanf("%d %d %d", &n, &k, &s);
    for (int i=1; i<=k; i++)
        scanf("%d", &b[i]),
        b[i] = s - b[i];
    
    sort(b+1, b+1+k);
    for (int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    
    build(1,1,k);
    
    for (int i=1; i<=n; i++)    l[i] = upper_bound(b+1, b+k+1, a[i]) - (b+1);
    for (int i=1; i<k; i++)     update(1,1,k,1,l[i],1);
    
    int ans = 0;
    for (int i=k; i<=n; i++) {
        update(1,1,k,1,l[i],1);
        int q = query(1,1,k,1,k);
        //cout<<q<<endl;
        if (q>=0)   ans++;
        update(1,1,k,1,l[i-k+1],-1);
    }
    
    cout<<ans<<endl;
}