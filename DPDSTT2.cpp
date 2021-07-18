#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1000009],e[1010000],dp[1000001];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=1e6; i++) e[i] = i;
    for (int i=2; i*i<=1e6; i++)
        if (e[i] == i)
        for (int j=2; j<=1e6/i; j++)
            if (e[j*i] == j*i) e[j*i] = i;
    int _check = *max_element(a+1,a+1+n);
    for (int i=1; i<=1e6; i++) dp[i] = 0;
    for (int i=1; i<=n; i++)
    {
        int p = a[i];
        int hs = 0;
        while (a[i] > 1)
        {
            int y = e[a[i]];
            dp[y]++;
            while (a[i] % y == 0) a[i] /= y;
            hs = max(hs,dp[y]);
        }
        while (p > 1)
        {
            int y = e[p];
            dp[y] = hs;
            while (p % y == 0) p /= y;
        }
    }
    cout << *max_element(dp+1,dp+_check+1);
    return 0;
}
    