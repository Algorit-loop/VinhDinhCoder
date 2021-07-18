#include <iostream>
#include <unordered_map>
using namespace std;
const int maxN = 30;
int a[maxN];
unordered_map<long long,long long> mymap;
int n;
long long sum1 = 0,sum2 = 0,ans = 0,d = 0;
void QL(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + a[x];
        if (i == 2) sum2 = sum2 + a[x];
        if (x < n/2) QL(x + 1);
        if (x == n/2) mymap[sum1-sum2]++;
        if (i == 1) sum1 = sum1 - a[x];
        if (i == 2) sum2 = sum2 - a[x];
    }
}
void _recursion(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + a[x];
        if (i == 2) sum2 = sum2 + a[x];
        if (x < n) _recursion(x + 1);
        if (x == n)
        {
            if(mymap.count(sum2-sum1) > 0)
                ans = ans + mymap[sum2-sum1];
        }
        if (i == 1) sum1 = sum1 - a[x];
        if (i == 2) sum2 = sum2 - a[x];
    }
}
int main()
{
    cin >> n ;
    for (int i=1; i<=n; i++) cin >> a[i];
    QL(1);
    _recursion(n/2+1);
    cout << ans - 1;
    return 0;
}
    