#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct _num
{
    int x , y , pos;
};
const int maxN = 2*1e5;
int n = 0,q,p,dp[maxN],grap[maxN],trace[maxN];
_num a[maxN];
vector<int> V;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> q)
    {
        if (q != 0)
        {
            cin >> p;
            n++;
            a[n].x = q;
            a[n].y = p;
            a[n].pos = n;
        }
        else break;
    }
    sort(a+1,a+1+n,[](const _num &u , const _num &v)
    {
        return (u.y > v.y || u.y == v.y && u.x < v.x);
    });
    int res = 1;
    dp[res] = a[1].x;
    grap[1] = 1;
    trace[1] = 0;
    int pos = 1;
    for (int i=2; i<=n; i++)
        if (dp[res] <= a[i].x)
        {
            dp[++res] = a[i].x;
            grap[res] = i;
            trace[i] = grap[res-1];
            pos = i;
        }
        else
        {
            int l = 1 , r = res , vt = 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (dp[mid] > a[i].x)
                {
                    r = mid - 1;
                    vt = mid;
                }
                else l = mid + 1;
            }
            dp[vt] = a[i].x;
            trace[i] = grap[vt-1];
            grap[vt] = i;
        }
    //for (int i=1; i<=n; i++) cout << a[i].x << " " << a[i].y <<"\n";
    cout << res << "\n";
    while (pos > 0)
    {
        V.push_back(a[pos].pos);
        pos = trace[pos];
    }
    reverse(V.begin(),V.end());
    for (auto x : V) cout << x <<" ";
}
    