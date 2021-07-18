#include <bits/stdc++.h>

using namespace std;
double x , y , u , v;
double _check(double n)
{
    double g1 = sqrt((n-x)*(n-x)+y*y);
    double g2 = sqrt((n-u)*(n-u)+v*v);
    return g1+g2;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> y;
    cin >> u >> v;
    double l = -1e9 , r = 1e9 , eps = 0.000001;
    while (r - l > eps)
    {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        if (_check(m1)<_check(m2)) r = m2;
        else l = m1;
    }
    cout << setprecision(5) << fixed << r;
    return 0;
}
    