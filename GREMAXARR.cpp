#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<long long,int> ii;
const int maxN = 2*1e5 + 113;
priority_queue<ii,vector<ii>,greater<ii>> heap;
ii a[maxN];
int n,k,x;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> x;
    for (int i=1; i<=n; i++) cin >> a[i].fi , a[i].se = i;
    int am = 0;
    for (int i=1; i<=n; i++)
        if(a[i].fi < 0) am++;
    for (int i=1; i<=n; i++) heap.push({abs(a[i].fi),a[i].se});
    for (; k>=1; k--)
    {
        ii _check = heap.top();
        heap.pop();
        if (am % 2 == 0)
        {
            if (a[_check.se].fi < 0)
            {
                a[_check.se].fi += x;
                if (a[_check.se].fi >= 0) am--;
            }
            else
            {
                a[_check.se].fi -= x;
                if (a[_check.se].fi < 0) am++;
            }
            heap.push({abs(a[_check.se].fi),_check.se});
        }
        else
        {
            if (a[_check.se].fi < 0) a[_check.se].fi -= x;
            else a[_check.se].fi += x;
            heap.push({abs(a[_check.se].fi),_check.se});
        }
    }
    for (int i=1; i<=n; i++) cout << a[i].fi << " ";
    return 0;
}
    