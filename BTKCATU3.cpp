#include <iostream>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;
const int maxN = 50;
int a[maxN],b[maxN];
vector<pair<long long,long long>> V;
int n;
long long m,sumW,sumV,res = 0;
void QL(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sumW = sumW + a[x],
                    sumV = sumV + b[x];
        if (x < n/2) QL(x + 1);
        if (x == n/2) V.push_back({sumW,sumV});
        if (i == 1) sumW = sumW - a[x],
                    sumV = sumV - b[x];
    }
}
void _check(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sumW = sumW + a[x],
                    sumV = sumV + b[x];
        if (x < n) _check(x + 1);
        if (x == n)
        {
            int l = 0 , r = V.size() - 1 , vt = 0;
            long long c = m - sumW;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if (V[mid].fi <= c) vt = mid , l = mid + 1;
                else r = mid - 1;
            }
            if (c >= 0) res = max(res,sumV + V[vt].se);
        }
        if (i == 1) sumW = sumW - a[x],
                    sumV = sumV - b[x];
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
    sumW = 0; sumV = 0;
    QL(1);
    sort(V.begin(),V.end());
    long long cnt = 0;
    for (int i=0; i<V.size(); i++)
    {
        cnt = max(cnt,V[i].se);
        V[i].se = cnt;
    }
    //for (int i=0; i<V.size(); i++) cout << V[i].fi <<" "; cout <<"\n";
    //for (int i=0; i<V.size(); i++) cout << V[i].se <<" "; cout <<"\n";
    sumW = 0; sumV = 0;
    _check(n/2+1);
    cout << res;
    return 0;
}
    