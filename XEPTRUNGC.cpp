#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[1000000],res = 0,mid;
bool _check(int mid)
{
    int sum = 0 , g = mid;
    for (int i=1; i<=n; i++)
        if (g >= a[i]) g = g - a[i];
        else sum = sum + 1 , g = mid - a[i];
    sum++;
    if (sum <= m) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >>m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int d = *max_element(a+1,a+1+n) , c = 3000000;
    while (d <=c )
    {
        mid = (d+c) / 2;
        if (_check(mid) == true)
        {
            res = mid;
            c = mid - 1;
        }
        else d = mid + 1;
    }
    cout << res;
    return 0;
}
    