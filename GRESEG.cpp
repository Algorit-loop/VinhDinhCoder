#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
struct _3num
{
    int x,y,pos;
};
_3num a[300000];
int n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].pos = i;
    }
    sort (a+1,a+1+n,[](const _3num &u , const _3num &v)
    {
        return ((u.x < v.x)||(u.x == v.x)&&(u.y > v.y));
    });
    int vt1 = 0,vt2 = 0;
    for (int i=2; i<=n; i++)
        if (a[i].y <= a[i-1].y)
    {
        vt1 = a[i].pos;
        vt2 = a[i-1].pos;
        return cout << vt1 << " " << vt2 ,0;
    }
    return cout << -1,0;
}
    