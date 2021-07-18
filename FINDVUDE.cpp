#include <iostream>

using namespace std;

int n,m,a[100010],b[100010];
long long check(int x)
{
    long long g = 0;
    for (int i=1; i<=n; i++)
        if (a[i] < x) g = g + x-a[i];
    for (int i=1; i<=m; i++)
        if (b[i] > x) g = g + b[i]-x;
    return g;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=m; i++)
        cin >> b[i];
    int l = 0 , r = 1e9;
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
    