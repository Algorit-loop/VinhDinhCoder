#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN = 40;
int a[maxN];
vector<long long> V;
long long sum = 0 , sumN = 0 , res = 1e18;
int n;
void QL(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sum = sum + a[x];
        if (x < n/2) QL(x+1);
        if (x == n/2) V.push_back(sum);
        if (i == 1) sum = sum - a[x];
    }
}
void _check(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sum = sum + a[x];
        if (x < n) _check(x +1);
        if (x == n)
        {
            long long c = sumN/2 - sum;
            int vt = lower_bound(V.begin(),V.end(),c) - V.begin();
            res = min(res,abs(sumN - 2*(V[vt]+sum)));
            if (vt - 1 >= 0) res = min(res,abs(sumN - 2*(V[vt-1]+sum)));
            if (vt + 1 < V.size()) res = min(res,abs(sumN - 2*(V[vt+1]+sum)));
            //cout << sum <<"\n";
        }
        if (i == 1) sum = sum - a[x];
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i] , sumN += a[i];
    QL(1);
    //cout << sumN <<"\n";
    sort(V.begin(),V.end());
    //for (auto x : V) cout << x << " "; cout <<"\n";
    sum = 0;
    _check(n/2+1);
    cout << res;
    return 0;
}
    