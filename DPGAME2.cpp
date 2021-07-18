#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 2*1e5;
int n,k;
int a[maxN];
long long dp[maxN],it[2*maxN];
vector<int> V;
long long query(int k,int L,int R,int d,int c)
{
    if (L > c || R < d) return -1e18;
    if (L >= d && R <= c)
    {
        return it[k];
    }
    int mid = (L+R) >> 1;
    return max(query(2*k,L,mid,d,c),query(2*k+1,mid+1,R,d,c));
}
void update(int k,int L,int R,int pos,long long val)
{
    if (L == R && R == pos)
    {
        it[k] = val;
        return;
    }
    int mid = (L+R) >> 1;
    if (pos > mid) update(2*k+1,mid+1,R,pos,val);
    else update(2*k,L,mid,pos,val);
    it[k] = max(it[2*k],it[2*k+1]);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    int d = 1,sum = 0;
    dp[0] = 0;
    for (int i=1; i<=n*4; i++) it[i] = -1e18;
    update(1,0,n,0,0);
    for (int i=1; i<=n ;i++)
    {
        dp[i] = query(1,0,n,max(i-k,0),i-1) + a[i];
        update(1,0,n,i,dp[i]);
    }
    //for (int i=1; i<=n; i++) cout << dp[i] <<" ";
    long long gtmax = 0;
    int vtmax = 0;
    for (int i=1; i<=n; i++)
        if (gtmax < dp[i]) gtmax = dp[i] , vtmax = i;
    V.push_back(vtmax);
    while (vtmax > 0)
    {
        int vt = 0;
        for (int i=vtmax-1; i>=max(0,vtmax-k); i--)
            if (dp[vtmax] == dp[i] + a[vtmax])
            {
                vtmax = i;
                V.push_back(vtmax);
                break;
            }
    }
    cout << *max_element(dp,dp+n+1) << "\n";
    /*cout << V.size() <<" ";
    sort(V.begin(),V.end());
    for (auto x : V ) cout << x << " ";*/
    return 0;
}
    