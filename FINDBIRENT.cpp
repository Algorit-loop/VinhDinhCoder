#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,a[100009],b[100006];
long long _coin = 0 , sum ;
bool _check(int mid)
{
    sum = 0;
    for (int i=1; i<=mid; i++)
        if (b[i] > a[n-mid+i]) sum = sum + b[i]-a[n-mid+i];
    return sum <=k;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >>n >> m >> k;
    for (int i=1; i<=n; i++)
        cin >>a[i];
    for (int i=1; i<=m; i++)
        cin >>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int d = 0, c = min(n,m) , res = 0;
    while (d <= c)
    {
        int mid = (d+c)/2;
        if (_check(mid)==true) res = mid ,_coin = sum, d = mid +1;
        else c = mid - 1;
    }
    cout << res << " " << _coin;
    return 0;
}
    