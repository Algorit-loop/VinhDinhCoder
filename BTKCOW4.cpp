#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN = 20;
int a[maxN] , chon[maxN] , n;
long long sum1 = 0 , sum2 = 0 , res = 0;
vector<pair<string,long long>> V;
vector<string> P;
void ql(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + a[x];
        if (i == 2) sum2 = sum2 + a[x];
        if (i == 3) chon[x] = 1;
        if (x < n) ql(x + 1);
        if (x == n && sum1 == sum2 && sum1 + sum2 >= res)
        {
            string s = "";
            for (int j=1; j<=n; j++)
                if (chon[j] == 1) s = s + to_string(j) + " ";
            bool _check = true;
            for (int j=0; j<V.size(); j++)
                if (V[j].first == s) _check = false;
            if (_check == true && s != "") V.push_back({s,sum1+sum2});
            res = max(res,sum1+sum2);
        }
        if (i == 1) sum1 = sum1 - a[x];
        if (i == 2) sum2 = sum2 - a[x];
        if (i == 3) chon[x] = 0;
    }
}
main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) chon[i] = 0;
    ql(1);
    cout << res << "\n";
    for (int i=0; i<V.size(); i++)
        if (V[i].second == res) P.push_back(V[i].first);
    if (P.size() == 0) cout << "OK";
    else
    {
        sort(P.begin(),P.end());
        for (auto x : P) cout << x << "\n";
    }
}
    