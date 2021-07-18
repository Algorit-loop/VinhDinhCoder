#include <iostream>
#include <algorithm>
using namespace std;
struct num
{
    long long x,y,val;
};
const int maxN = 10000;
num a[maxN];
long long dp[maxN];
int t,n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (; t>=1 ;t--)
    {
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i].x >> a[i].y >> a[i].val;
        for (int i=1; i<=n; i++)
            a[i].y = a[i].x + a[i].y - 1;
        sort(a+1,a+1+n,[](const num &u,const num &v)
        {
            return (u.y < v.y || u.y == v.y && u.x < v.x);
        });
        long long res = 0;
        for (int i=1; i<=n; i++)
        {
            long long cnt = 0;
            for (int j=i-1; j>=1; j--)
                if (a[i].x > a[j].y) cnt = max(cnt,dp[j]);
            dp[i] = a[i].val + cnt;
            res = max(res,dp[i]);
        }
        //cout << "===========================\n";
        //for (int i=1; i<=n; i++) cout << a[i].x<< " " << a[i].y << " " << a[i].val <<"\n";
        //for (int i=1; i<=n; i++) cout << dp[i] << " "; cout << "\n";
        cout << res << "\n";
    }
    return 0;
}
    