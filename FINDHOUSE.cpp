#include <iostream>
#include <algorithm>
using namespace std;

int a[300000],n,b[300000];
long long check(int x)
{
    long long g = 0;
    for (int i=1; i<=n; i++)
        g = g + 1LL*abs(x-a[i])*b[i];
    return g;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    int l = 0 , r = *max_element(a+1,a+1+n);
    while (r - l > 3)
    {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if (check(m1)<check(m2)) r = m2;
        else l = m1;
    }
    long long ans = 1e18;
    for (int i=l; i<=r; i++)
        ans = min(ans,check(i));
    cout << ans;
    return 0;
}
    