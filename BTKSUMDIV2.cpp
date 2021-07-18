#include <iostream>
#include <unordered_map>
using namespace std;
const int maxN = 50;
int a[maxN];
unordered_map<long long,long long> mymap;
int n;
long long sum = 0,k,d = 0,res = 0;
void QL(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sum = sum + a[x] , d++;
        if (x < n/2) QL(x + 1);
        if (x == n/2) mymap[sum%k] = max(mymap[sum%k],d);
        if (i == 1) sum = sum - a[x] , d--;
    }
}
void _check(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1) sum = sum + a[x] , d++;
        if (x < n) _check(x + 1);
        if (x == n)
        {
            long long p = k - sum%k;
            if (p == k) p = 0;
            if (mymap.count(p) > 0)
            {
                res = max(res,d + mymap[p]);
            }
        }
        if (i == 1) sum = sum - a[x] , d--;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    QL(1);
    sum = 0;
    _check(n/2+1);
    cout << res;
    return 0;
}
    