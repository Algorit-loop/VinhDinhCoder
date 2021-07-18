#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
const int maxN = 2*1e5;
ii a[maxN];
int n , dp[maxN];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a+1,a+1+n,[](const ii &u , const ii & v)
         {
             return (u.se > v.se || u.se == v.se && u.fi < v.fi);
         });
    //cout << "====================\n";
    //for (int i=1; i<=n; i++) cout << a[i].fi << " " << a[i].se <<"\n";
    //cout << "====================\n";
    int res = 1;
    dp[res] = a[1].fi;
    for (int i=2; i<=n; i++)
    {
        if (dp[res] <= a[i].fi) dp[++res] = a[i].fi;
        else
        {
            int l = 1 , r = res , vt = 1;
            while (l <= r)
            {
                int mid = (l+r) / 2;
                if (dp[mid] > a[i].fi)
                {
                    vt = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            dp[vt] = a[i].fi;
        }
        //for (int j=1; j<=res; j++) cout << dp[j] << " "; cout <<"\n";
    }
    cout << res;
    return 0;
}
    