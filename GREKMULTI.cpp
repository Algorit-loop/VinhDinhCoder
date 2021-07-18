#include <bits/stdc++.h>

using namespace std;
const int maxN = 2*1e5;
set<int> p;
int n , k , a[maxN];
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    p.insert(a[1]);
    for (int i=2; i<=n; i++)
    {
        int q = a[i] / k;
        if (p.find(q) == p.end() || a[i] % k != 0) p.insert(a[i]);
    }
    cout << p.size();
    return 0;
}
    