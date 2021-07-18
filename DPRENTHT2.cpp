#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
pair <int,int> a[1000000];
int n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a+1,a+1+n,[](const pair<int,int> &u,const pair<int,int> &v)
    {
        return (u.se < v.se);
    });
    int res = 0, finish = 0;
    for (int i=1; i<=n; i++)
        if (a[i].fi > finish )
        {
            res++;
            finish = a[i].se;
        }
    cout << res;
    return 0;
}
    