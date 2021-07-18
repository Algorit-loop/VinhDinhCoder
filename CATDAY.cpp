#include <iostream>

using namespace std;

int n,k,a[100009];
long long _check(int mid)
{
    long long sum = 0;
    for (int i=1; i<=n; i++)
        sum = sum + a[i]/mid;
    return sum;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >>k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int d = 1,c = 1e9,res = 0;
    while (d <= c)
    {
        int mid = (d+c)/2;
        if (_check(mid) >= k) res = mid , d = mid +1;
        else c = mid -1;
    }
    cout << res;
    return 0;
}
    