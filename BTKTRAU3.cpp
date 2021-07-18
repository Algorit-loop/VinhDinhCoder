#include <iostream>
#include <unordered_map>

using namespace std;
const int maxN = 40;
int a[maxN];
int n;
long long sum = 0 , s , d , cnt , res = 0;
unordered_map<long long,long long> dp,mymap;
void QL(int x)
{
    for (int i=0; i<=1; i++)
    {
        if (i == 1) sum = sum + a[x] , d++;
        if (x < n/2) QL(x + 1);
        if (x == n/2)
        {
            mymap[sum]++;
            if (dp[sum] != 0) dp[sum] = min(dp[sum],d);
            else dp[sum] = d;
        }
        if (i == 1) sum = sum - a[x] , d--;
    }
}
void _check(int x)
{
    for (int i=0; i<=1; i++)
    {
        if (i == 1) sum = sum + a[x] , d++;
        if (x < n) _check(x + 1);
        if (x == n)
            if (mymap.count(s - sum) > 0)
            {
                res = res + mymap[s-sum];
                cnt = min(cnt,d + dp[s-sum]);
            }
        if (i == 1) sum = sum - a[x] , d--;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i=1; i<=n; i++) cin >> a[i];
    sum = 0 , d = 0;
    QL(1);
    sum = 0 , d = 0 , cnt = n;
    _check(n/2+1);
    if (res != 0) cout << res <<" "<<cnt;
    else cout << "KHONG CHON DUOC";
    return 0;
}
    