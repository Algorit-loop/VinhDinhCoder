#include <iostream>
#include <unordered_map>
using namespace std;

int n,a[100005],dp[100005],res = 0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int d=1; d<=50; d++)
    {
        for (int i=1; i<=n; i++) dp[i] = 1;
        unordered_map<int,int> mymap;
        for (int i=1; i<=n; i++)
        {
            if (mymap.count(a[i]-d) > 0)
                dp[i] = mymap[a[i]-d] + 1;
            mymap[a[i]] = max(mymap[a[i]],dp[i]);
            res = max(res,dp[i]);
        }
    }
    cout << res;
    return 0;
}
    