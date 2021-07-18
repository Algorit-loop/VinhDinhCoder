#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
const int maxN = 2*1e5;
ii a[maxN];
int dpfi[maxN],dpse[maxN];
int n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a+1,a+1+n,[](const ii &u , const ii &v)
    {
        return (u.se < v.se || u.se == v.se && u.fi < v.fi);
    });
    dpfi[1] = a[1].fi;
    dpse[1] = a[1].se;
    int res = 1;
    for (int i=2; i<=n ;i++)
    {
        if (a[i].fi >= dpfi[res] && a[i].se >= dpse[res])
        {
            res++;
            dpfi[res] = a[i].fi;
            dpse[res] = a[i].se;
        }
        else
        {
            int L = 1 , R = res , vt = 1;
            while (L <= R)
            {
                int mid = (L + R) >> 1;
                if (dpfi[mid] <= a[i].fi && dpse[mid] <= a[i].se) vt = mid + 1 , L = mid + 1;
                else R = mid - 1;
            }
            dpfi[vt] = a[i].fi;
            dpse[vt] = a[i].se;
        }
    }
    cout << n - res;
    return 0;
}