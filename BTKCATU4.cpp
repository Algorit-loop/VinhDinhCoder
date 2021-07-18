#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<long long,long long> ii;
int a[50] , b[50];
int n;
long long l , r , sumW , sumV , res = 0;
long long it[5*1000000];
vector<pair<long long,long long>> V;
long long query(int k,int L,int R,int u, int v)
{
    if (L > v || R < u) return -1e18;
    if (L >= u && R <= v) return it[k];
    int mid = (L+R) >> 1;
    return max(query(2*k,L,mid,u,v),query(2*k+1,mid+1,R,u,v));
}
void ql(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sumW = sumW + a[x],
                    sumV = sumV + b[x];
        if (x < n/2) ql(x + 1);
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
            long long cnt = 0;
            int d = 0 , c = V.size()-1 , vttren = 0;
            while (d <= c)
            {
                int mid = (d + c) / 2;
                if (V[mid].fi <= r - sumW) vttren = mid , d = mid + 1;
                else c = mid - 1;
            }
            d = 0 , c = V.size()-1;
            int vtduoi = V.size();
            while (d <= c)
            {
                int mid = (d + c) / 2;
                if (V[mid].fi >= l - sumW) vtduoi = mid , c = mid - 1;
                else d = mid + 1;
            }
            cnt = query(1,1,V.size()-1,vtduoi,vttren);
            res = max(res,sumV + cnt);
        }
        if (i == 1) sumW = sumW - a[x],
                    sumV = sumV - b[x];
    }
}
void built(int k,int L,int R)
{
    if (L == R)
    {
        it[k] = V[L].se;
        return;
    }
    int mid = (L+R) >> 1;
    built(2*k,L,mid);
    built(2*k+1,mid+1,R);
    it[k] = max(it[2*k],it[2*k+1]);
}
int main()
{
    cin >> n >> l >> r;
    for (int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
    ql(1);
    sumW = 0; sumV = 0;
    V.push_back({0,0});
    sort(V.begin(),V.end());
    built(1,1,V.size()-1);
    //for (auto x : V) cout << x.fi << " "; cout << "\n";
    sumW = 0; sumV = 0;
    _check(n/2+1);
    cout << res;
    return 0;
}
    