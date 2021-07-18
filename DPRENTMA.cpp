#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
const int maxN = 2*1e5;
pair<int,int> a[maxN];
long long dp[maxN];
int n;
int main()
{
    ios::sync_with_stdio(false); cin.tie(false); cout.tie(false);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a+1,a+1+n);
    dp[1] = a[1].se - a[1].fi + 1;
    for (int i=2; i<=n; i++)
    {
        dp[i] = a[i].se - a[i].fi + 1;
        long long k = dp[i];
        for (int j=i-1; j>=1; j--)
            if (a[i].fi > a[j].se) dp[i] = max(dp[i] , dp[j] + k);
    }
    cout << *max_element(dp+1,dp+1+n);
    return 0;
}
    