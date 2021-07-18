#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 2*1e5+100;
long long n , k;
int a[maxN];
priority_queue<ll,vector<ll>,greater<ll>> hmin;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    long long ans = 0 , gtmax = a[1] , vt = 1;
    hmin.push(a[n]+n*k);
    for (int i=n-1; i>=1; i--)
    {
        long long sum = a[i] + k*i - hmin.top();
        ans = max(ans,sum);
        hmin.push(a[i] + k*i);
    }
    cout << ans;
    return 0;
}
=======================
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 2*1e5+100;
long long n , k;
int a[maxN];
priority_queue<ll,vector<ll>,greater<ll>> hmin;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    long long ans = 0 , gtmin = a[n] + n*k;
    //hmin.push(a[n]+n*k);
    for (int i=n-1; i>=1; i--)
    {
        long long sum = a[i] + k*i - gtmin;
        ans = max(ans,sum);
        gtmin = min(gtmin,a[i]+k*i);
    }
    cout << ans;
    return 0;
}
    