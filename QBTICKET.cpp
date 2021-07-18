#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 2*1e5;
int n,s,f;
long long C1,C2,C3,L1,L2,L3;
long long a[maxN];
long long dp[maxN];
long long Tree[4*maxN];
void update(int k,int L,int R,int pos,long long val)
{
    if (L == R && R == pos)
    {
        Tree[k] = val;
        return;
    }
    int mid = (L + R) >> 1;
    if (pos > mid) update(2*k+1,mid+1,R,pos,val);
    else update(2*k,L,mid,pos,val);
    Tree[k] = min(Tree[2*k],Tree[2*k+1]);
}
long long query(int k,int L,int R,int u,int v)
{
    if (L > v || R < u) return 1e18;
    if (L >= u && R <= v) return Tree[k];
    int mid = (L + R) >> 1;
    return min(query(2*k,L,mid,u,v),query(2*k+1,mid+1,R,u,v));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> L1 >> L2 >> L3;
    cin >> C1 >> C2 >> C3;
    cin >> n >> s >> f;
    for (int i=2; i<=n; i++) cin >> a[i];
    //for (int i=1; i<=4*n; i++) Tree[i] = 1e18;
    a[1] = 1;
    dp[s] = 0;
    update(1,1,n,s,0);
    for (int i=s+1; i<=f; i++)
    {
        long long cnt = 1e18;
        int x1 = lower_bound(a+s,a+s+(i-s),a[i] - L1) - a;
        int x2 = lower_bound(a+s,a+s+(i-s),a[i] - L2) - a;
        int x3 = lower_bound(a+s,a+s+(i-s),a[i] - L3) - a;
        cnt = min(cnt,query(1,1,n,x1,i-1) + C1);
        cnt = min(cnt,query(1,1,n,x2,i-1) + C2);
        cnt = min(cnt,query(1,1,n,x3,i-1) + C3);
        dp[i] = cnt;
        update(1,1,n,i,dp[i]);
    }
    //for (int i=s; i<=f; i++) cout << dp[i] <<" ";
    cout << dp[f];
    return 0;
}
    