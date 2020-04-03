#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int k, n;
double p[200];
double p2[200];
double d[201][101];

double dp()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i <= k; i ++)
    {
        for (int j = 0; j <= k / 2; j ++)
        {
            if (i == 0)
            {
                d[i][j] = (j == 0);
            }
            else
            {
                d[i][j] = p2[i - 1] * d[i - 1][j - 1] +
                (1 - p2[i - 1])* d[i - 1][j];
            }
        }
    }
    cout<<d[k][k/2]<<endl;
    return d[k][k / 2];
}

int main()
{
    int t, ct;
    freopen("/Users/shashanksaurabh/Desktop/Journey/GoogleCodeJam1/GoogleCodeJam1/B-small-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/GoogleCodeJam1/GoogleCodeJam1/ansSmallright.txt","w",stdout);
    cin >> ct;
    for (t = 1; t <= ct; t++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i ++)
        {
            cin >> p[i];
        }
        
        sort(p, p + n);
        
        double ans = 0;
        for (int i = 0; i <= k; i ++)
        {
            for (int j = 0; j < k; j ++)
            {
                if (j < i)
                {
                    p2[j] = p[j];
                }
                else
                {
                    p2[j] = p[j + n - k];
                }
            }
            double cur = dp();
            if (cur > ans)
            {
                ans = cur;
            }
        }
        cout<<ans<<endl;
        printf("Case #%d: %.8lf\n", t, ans);
        for (int i = 0; i <= k; i ++)
        {
            for (int j = 0; j <= k / 2; j ++)
            {
                cout<<d[i][j]<<'\t'<<'\t';
            }
            cout<<endl;
        }
        cout<<"------------------------------------------------"<<endl;
    }
    
    return 0;
}
