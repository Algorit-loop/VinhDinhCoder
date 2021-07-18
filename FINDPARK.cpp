#include <iostream>
#define llong long long
using namespace std;
llong n , m , c1 , c2;
llong check(int x)
{
    llong res = 0;
    llong g1 = n / x;
    llong du = n % x;
    res = res + (x-du)*(c1 + c2*(g1-1)*(g1-1));
    res = res + du*(c1 + c2*(g1)*(g1));
    return res;
}
int main()
{
    cin >> n >> m >> c1 >> c2;
    int l = 1 , r = m ;
    while (r - l > 3)
    {
        int m1 = l + (r - l)/3;
        int m2 = r - (r - l)/3;
        if (check(m1)<check(m2)) r = m2;
        else l = m1;
    }
    llong ans = 1e18 , g;
    //for (int i=1; i<=m; i++) if (ans > check(i)) ans = check(i) , g = i;
    for (int i=l; i<=r; i++)
        ans = min(ans,check(i));
    cout << ans <<" ";
    //cout <<g;
    return 0;
}
    