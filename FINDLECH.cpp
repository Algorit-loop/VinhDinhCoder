#include <iostream>

using namespace std;

long long n,k,a[1000000],u,v;
long long _check(int x)
{
    return abs((a[x]-a[u-1])-(a[v]-a[x]));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >>k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=2; i<=n; i++)
        a[i] = a[i-1] + a[i];
    for (int t=1; t<=k; t++)
    {
        cin >> u >> v;
        int l = u , r = v ;
        while (r - l > 3)
        {
            int m1 = l + (r - l)/3;
            int m2 = r - (r - l)/3;
            if (_check(m1)<_check(m2)) r = m2;
            else l = m1;
        }
        long long ans = 1e18;
        for (int i=l; i<=r; i++) ans = min(ans,_check(i));
        cout << ans <<"\n";
    }
    return 0;
}
    