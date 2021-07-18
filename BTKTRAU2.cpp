#include <bits/stdc++.h>

using namespace std;
int a[100],b[100],c[100];
long long n , s , sum = 0 , k = 0;
unordered_map<long long,string> mymap;
bool res = false;
string g = "";
void ql(int x)
{
    for (int i=0; i<=1; i++)
    {
        if (i == 1) sum = sum + a[x] , g = g + "1";
        else g = g + "0";
        if (x < n/2) ql(x+1);
        if (x == n/2) mymap[sum] = g;
        if (i == 1) sum = sum - a[x];
        g.erase(g.size()-1,1);
    }
}
void _check(int x)
{
    for (int i=0; i<=1; i++)
    {
        if (i == 1) sum = sum + b[x] , g = g + "1";
        else g = g + "0";
        if (x < k) _check(x +1);
        if (x == k) if (mymap.count(s-sum) != 0)
        {
            cout << "YES" <<"\n";
            g = mymap[s-sum] + g;
            int d = 0;
            for (int j=0; j<g.size(); j++)
                if (g[j] == '1') d++;
            cout << d <<"\n";
            for (int j=0; j<g.size(); j++)
                if (g[j] == '1') cout << j+1 <<" ";
            exit(0);
        }
        if (i == 1) sum = sum - b[x];
        g.erase(g.size()-1,1);
    }
}
int main()
{
    cin >> n >> s;
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=1; i<=n/2; i++) a[i] = c[i];
    for (int i=n/2+1; i<=n; i++) b[++k] = c[i];
    sum = 0;
    ql(1);
    sum = 0;
    _check(1);
    cout << "NO";
    return 0;
}
    