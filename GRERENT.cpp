#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxN = 3*1e5;
typedef pair<int,int> ii;
priority_queue<int,vector<int>,greater<int>> p;
ii a[maxN];
int n;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].fi;
    for (int i=1; i<=n; i++) cin >> a[i].se;
    sort(a+1,a+1+n);
    p.push(a[1].fi + a[1].se);
    for (int i=2; i<=n; i++)
    {
        if (p.top() <= a[i].fi)
        {
            p.pop();
            p.push(a[i].fi + a[i].se);
        }
        else
        {
            p.push(a[i].fi + a[i].se);
        }
    }
    cout << p.size();
    return 0;
}
    