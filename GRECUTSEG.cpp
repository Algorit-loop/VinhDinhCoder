#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
unordered_map<int,int> f;
vector<ii> dp;
int a[100010],n,t;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for (int j=1; j<=t; j++)
    {
        f.clear(); dp.clear();
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        int d = 1;
        for (int i=1; i<=n; i++)
        {
            f[a[i]]++;
            if (f[a[i]] == 2)
            {
                dp.push_back({d,i}),f.clear();
                d = i+1;
            }
        }
        if (d == 1) cout<<-1<<"\n";
        else
        {
            if (d<=n) dp[dp.size()-1].second = n;
            for (auto x:dp) cout << x.first <<" "<<x.second <<"\n";
        }
    }
    return 0;
}
    