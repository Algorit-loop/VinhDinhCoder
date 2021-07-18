#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s , ans = "";
int nd = 0,nm = 0,n;
vector<string> V , P;
void QL(int x)
{
    for (int i=0; i<2; i++)
    {
        if (i == 1)
        {
            ans = ans + s[x];
            if (s[x] == '(') nm++;
            if (s[x] == ')') nd++;
        }
        if (x < n && nm >= nd) QL(x + 1);
        if (x == n && nm == nd && nd != 0) V.push_back(ans);
        if (i == 1)
        {
            ans.erase(ans.size()-1,1);
            if (s[x] == '(') nm--;
            if (s[x] == ')') nd--;
        }
    }
}
int main()
{
    cin >> s;
    n = s.size();
    s = "@" + s;
    QL(1);
    if (V.size() != 0)
    {
        sort(V.begin(),V.end());
        P.push_back(V[0]);
        for (int i=1; i<V.size(); i++)
            if (V[i] != V[i-1]) P.push_back(V[i]);
        cout << P.size() << "\n";
        for (auto x : P) cout << x << "\n";
    } else cout << 0;
    return 0;
}
    