#include <iostream>

using namespace std;

int a[100009],b[100009],t,n,m;
long long check(long long mid)
{
    long long g1 = 0 , g2 = 0;
    for (int i=1; i<=n; i++)
        g1 = g1 + mid/a[i];
    for (int i=1; i<=m; i++)
        g2 = g2 + (t-mid)/b[i];
    return min(g1,g2);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> b[i];
    long long r = t , l = 0 , ans = 0;
    while (r - l > 3)
    {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if (check(m1)<check(m2)) l = m1;
        else r = m2;
    }
    for (int i=l; i<=r; i++)
        ans = max(ans,check(i));
    cout << ans;
    return 0;
}
    