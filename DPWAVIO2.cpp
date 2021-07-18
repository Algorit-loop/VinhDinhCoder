#include <iostream>
#include <algorithm>
using namespace std;
int a[300000],f1[300000],dp[300000],f2[300000];
int n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    f1[1] = 1;
    dp[1] = a[1];
    int res = 1;
    for (int i=2; i<=n; i++)
    {
        if (dp[res] < a[i])
        {
            dp[++res] = a[i];
            f1[i] = res;
        }
        else
        {
            int x = lower_bound(dp+1,dp+1+res,a[i]) - dp;
            dp[x] = a[i];
            f1[i] = x;
        }
    }
    for (int i=1; i<=n; i++) dp[i] = 0;
    dp[1] = a[n];
    res = 1;
    f2[n] = 1;
    for (int i=n-1; i>=1; i--)
    {
        if (dp[res] < a[i])
        {
            dp[++res] = a[i];
            f2[i] = res;
        }
        else
        {
            int x = lower_bound(dp+1,dp+1+res,a[i]) - dp;
            dp[x] = a[i];
            f2[i] = x;
        }
    }
    //for (int i=1; i<=n; i++) cout << f1[i] << " " ; cout << "\n";
    //for (int i=1; i<=n; i++) cout << f2[i] << " " ; cout << "\n";
    int result = 1;
    for (int i=1; i<=n; i++)
        if (f1[i] != 1 && f2[i] != 1) result = max(result,f1[i]+f2[i] - 1);
    cout << result;
}
    