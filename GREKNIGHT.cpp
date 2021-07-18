#include <bits/stdc++.h>
#define llong long long
using namespace std;
const int maxN = 2*1e6;
struct num
{
    long long x , y , pos;
};
priority_queue<llong,vector<llong>,greater<llong>> heap , gre;
num a[maxN];
long long ans[maxN];
int n,k;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n ;i++)
        cin >> a[i].x ;
    for (int i=1; i<=n; i++)
        cin >> a[i].y , a[i].pos = i;
    sort(a+1,a+1+n,[](const num &u , const num &v)
    {
        return (u.x < v.x);
    });
    ans[a[1].pos] = a[1].y;
    heap.push(a[1].y);
    llong sum = a[1].y;
    for (int i=2; i<=n; i++)
    {
        if (heap.size() > k)
        {
            sum = sum - heap.top();
            heap.pop();
        }
        sum = sum + a[i].y;
        ans[a[i].pos] = sum;
        heap.push(a[i].y);
    }
    for (int i=1; i<=n; i++) cout << ans[i] <<" ";
    return 0;
}
    