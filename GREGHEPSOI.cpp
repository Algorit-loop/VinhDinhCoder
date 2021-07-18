#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 2*1e5;
int n , R;
priority_queue<ll,vector<ll>,greater<ll>> hmin;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> R;
        hmin.push(R);
    }
    long long ans = 0;
    for (int i=1; i<n; i++)
    {
        long long k = hmin.top();
        hmin.pop();
        k = k + hmin.top();
        hmin.pop();
        hmin.push(k);
        ans = ans + k;
    }
    cout << ans;
    return 0;
}
    