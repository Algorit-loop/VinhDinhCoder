#include <iostream>

using namespace std;
long long s;
int n,a[100009];
bool _check ( int mid )
{
    long long sum = 0;
    for (int i=1; i<=n; i++)
        if (a[i] < mid) sum = sum + a[i];
    else sum = sum + mid;
    return sum >= s;
}
int main()
{
    cin >> n >>s;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int d = 0, c = 1e6 , res = -1;
    while (d <= c)
    {
        int mid = (d+c) / 2;
        if (_check(mid)==true) res = mid , c = mid -1;
        else d = mid +1;
    }
    cout << res;
    return 0;
}
    