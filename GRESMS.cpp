#include <bits/stdc++.h>

using namespace std;
const int maxN = 2*1e5;
unordered_map<string,int> mymap;
string s[maxN] , cp[maxN];
int b[maxN] , a[maxN] , f[maxN];
int n , k , m;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=k; i++)
    {
        int x , g;
        cin >> x;
        for (int j=1; j<=x; j++)
        {
            cin >> g ;
            b[g] = i;
        }
    }
    for (int i=1; i<=n; i++) f[i] = 1e9;
    for (int i=1; i<=m; i++) cin >> cp[i];
    for (int i=1; i<=n; i++)
        f[b[i]] = min(f[b[i]],a[i]);
    for (int i=1; i<=n; i++)
        mymap[s[i]] = i;
    long long ans = 0;
    for (int i=1; i<=m; i++)
    {
        int y = mymap[cp[i]];
        y = b[y];
        if (y == 0) ans = ans + a[mymap[cp[i]]];
        else ans = ans + f[y];
    }
    cout << ans;
    return 0;
}
    