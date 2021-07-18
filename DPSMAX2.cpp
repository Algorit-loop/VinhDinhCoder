#include <iostream>
#define fi first
#define se second
using namespace std;
const int maxN = 2*1e5;
int a[maxN];
long long dp[maxN];
int n;
pair<long long,long long> SegTree[4*maxN];
void update(int k,int L,int R,int pos,long long val1,long long val2)
{
    if (L == R && L == pos)
    {
        SegTree[k] = {val1,val2};
        return;
    }
    int mid = (L + R) >> 1;
    if (pos > mid && pos <= R) update(2*k+1,mid+1,R,pos,val1,val2);
    if (pos <= mid && pos >= L) update(2*k,L,mid,pos,val1,val2);
    SegTree[k].se = max(SegTree[2*k].se,SegTree[2*k+1].se);
    SegTree[k].fi = max(SegTree[2*k].fi,SegTree[2*k+1].fi);
}
long long query(int k,int L,int R, int u,int v,long long _check)
{
    if (L > v || R < u) return -1e18;
    if (L >= u && R <= v && SegTree[k].fi <= _check)
        return SegTree[k].se;
    int mid = (L + R) >> 1;
    return max(query(2*k,L,mid,u,v,_check),query(2*k+1,mid+1,R,u,v,_check));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    long long res = 0;
    for (int i=1; i<=n; i++)
    {
        dp[i] = query(1,0,n,0,i-1,a[i]) + a[i];
        update(1,1,n,i,a[i],dp[i]);
        res = max(res,dp[i]);
    }
    //for (int i=1; i<=n; i++) cout << dp[i] << " "; cout << "\n";
    cout << res;
    return 0;
}
    