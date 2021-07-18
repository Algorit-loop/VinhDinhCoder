#include <bits/stdc++.h>
 
using namespace std;
 
int n;
double a[100009];
double _goc(double mid)
{
    double k = 0;
    for (int i=1; i<=n; i++)
    {
        double x = a[i]+a[i+1],y = a[i]+mid,z = a[i+1]+mid;
        k = k + acos((z*z+y*y-x*x)/(2*y*z));
    }
    return k;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    a[n+1] = a[1];
    double d = 0, c = 1e9 ,eps = 0.000000001;
    while ( c-d > eps)
    {
        double mid = (d+c)/2;
        if (_goc(mid)>=2*acos(-1)) d = mid;
        else c = mid;
    }
    cout << setprecision(3) << fixed << d;
    return 0;
}