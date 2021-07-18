#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
const int maxN = 2*1e5;
long long a[maxN],b[maxN];
long long dp[maxN];
pair<long long,long long> Tree[8*maxN];
int n,p;
long long query(int k,int L,int R,int u,int v,long long check)
{
    if (L > v || R < u) return -1e18;
    if (L == R && abs(check - Tree[k].fi) < p) return 0;
    if (L >= u && R <= v)
    {
        if (abs(check - Tree[k].fi) >= p) return Tree[k].se;
        //if (L == u && R == v) return -1e18;
        //return -1e18;
    }
    int mid = (L + R) >> 1;
    return max(query(2*k,L,mid,u,v,check),query(2*k+1,mid+1,R,u,v,check));
}
void update(int k,int L,int R,int pos,long long GT1,long long GT2)
{
    if (L == R && R == pos)
    {
        Tree[k] = {GT1,GT2};
        return;
    }
    int mid = (L + R) >> 1;
    if (pos > mid) update(2*k+1,mid+1,R,pos,GT1,GT2);
    else update(2*k,L,mid,pos,GT1,GT2);
    Tree[k].fi = max(Tree[2*k].fi,Tree[2*k+1].fi);
    Tree[k].se = max(Tree[2*k].se,Tree[2*k+1].se);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    long long res = b[1];
    dp[1] = b[1];
    update(1,1,n,1,a[1],dp[1]);
    for (int i=2; i<=n; i++)
    {
        dp[i] = query(1,1,n,1,i-1,a[i]) + b[i];
        update(1,1,n,i,a[i],dp[i]);
        res = max(res,dp[i]);
    }
    //for (int i=1; i<=n; i++) cout << dp[i] <<" ";
    cout << res;
    return 0;
}
    