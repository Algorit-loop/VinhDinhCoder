#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 3*1e5;
int n , m , f[maxN] ,t;
long long a[maxN], dp[maxN];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (; t>=1; t--)
    {
        cin >> n >> m;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        int res = 1;
        dp[res] = a[1];
        f[1] = 1;
        for (int i=2; i<=n; i++)
            if (dp[res] > a[i]) dp[++res] = a[i] , f[i] = res;
            else
            {
                int x = 1 , l = 1 , r = res;
                while (l <= r)
                {
                    int mid = (l+r)/2;
                    if (dp[mid] <= a[i])
                    {
                        x = mid;
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }
                dp[x] = a[i];
                f[i] = x;
            }
        //for (int i=1; i<=res; i++) cout << dp[i] <<" "; cout << "\n";
        //for (int i=1; i<=n; i++) cout << f[i] << " "; cout << "\n";
        int ans = *max_element(f+1,f+1+n);
        res = 1;
        dp[res] = a[m+1];
        f[m+1] = 1;
        for (int i=m+2; i<=n; i++)
            if (dp[res] > a[i]) dp[++res] = a[i] , f[i] = res;
            else
            {
                int x = 1 , l = 1 , r = res;
                while (l <= r)
                {
                    int mid = (l+r)/2;
                    if (dp[mid] <= a[i])
                    {
                        x = mid;
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }
                dp[x] = a[i];
                f[i] = x;
            }
        //for (int i=1; i<=n; i++) cout << f[i] <<" "; cout << "\n";
        int p = 0;
        for (int i=m+1; i<=n; i++) p = max(p,f[i]);
        //cout << p <<"\n";
        ans = max(ans , f[m] + p);
        cout << ans <<"\n";
    }
    return 0;
}
    