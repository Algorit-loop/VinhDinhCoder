#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN = 30;
long long n , m , cnt = 0;
int a[maxN];
char dau[maxN];
string s = "";
vector<string> V;
void _check()
{
    s = to_string(a[1]);
    for (int i=2; i<=n; i++)
    {
        if (a[i] > 0 && dau[i] == '+' || a[i] < 0 && dau[i] == '-')
            s = s + "+" + to_string(abs(a[i]));
        else if (a[i] != 0) s = s + "-" + to_string(abs(a[i]));
        if (a[i] == 0) s = s + dau[i] + to_string(abs(a[i]));
    }
    V.push_back(s);
}
void recur(int x)
{
    for (int i=0; i<=1; i++)
    {
        if (i == 0)
        {
            cnt = cnt + a[x];
            dau[x] = '+';
        }
        if (i == 1)
        {
            cnt = cnt - a[x];
            dau[x] = '-';
        }
        if (x == n && cnt == m) _check();
        if (x < n) recur(x+1);
        if (i == 0) cnt = cnt - a[x]; else cnt = cnt + a[x];
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cnt = a[1];
    recur(2);
    sort(V.begin(),V.end());
    for (auto x : V) cout << x << "\n";
    return 0;
}
    