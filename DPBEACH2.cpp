#include <iostream>

using namespace std;
const int maxN = 2*1e5;
int a[maxN],dp[maxN],F1[maxN],F2[maxN];
int n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    dp[1] = a[n];
    F1[n] = 1;
    int res = 1;
    for (int i=n-1; i>=1; i--)
    {
        if (a[i] < dp[res])
        {
            dp[++res] = a[i];
            F1[i] = res;
        } else
        {
            int L = 1 , R = res , vt = 1;
            while (L <= R)
            {
                int mid = (L + R) >> 1;
                if (dp[mid] <= a[i]) R = mid - 1 , vt = mid;
                else L = mid + 1;
            }
            dp[vt] = a[i];
            F1[i] = vt;
        }
    }
    dp[1] = a[n];
    F2[n] = 0;
    res = 1;
    for (int i=n-1; i>=1; i--)
    {
        if (dp[res] < a[i])
        {
            dp[++res] = a[i];
            F2[i] = res - 1;
        } else
        {
            int L = 1 , R = res , vt = 1;
            while (L <= R)
            {
                int mid = (L + R) >> 1;
                if (dp[mid] >= a[i]) R = mid - 1 , vt = mid;
                else L = mid + 1;
            }
            dp[vt] = a[i];
            F2[i] = vt - 1;
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) ans = max(ans,F1[i] + F2[i]);
    cout << ans;
    return 0;
}
    