#include <iostream>
#include <vector>
using namespace std;
string s = "";
int n,nd = 0,nm = 0;
vector<string> V;
void recur(int x)
{
    for (int i=0; i<2; i++)
        if (i == 0 || i == 1 && nd + 1 <= nm)
        {
            if (i == 0)
            {
                s = s + "(";
                nm++;
            }
            if (i == 1)
            {
                s = s + ")";
                nd++;
            }
            if (x == n && nm == nd) V.push_back(s);
            if (x < n) recur(x+1);
            s.erase(s.size()-1,1);
            if (i == 0) nm--; else nd--;
        }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    recur(1);
    cout << V.size() <<"\n";
    for (auto x : V) cout << x << "\n";
    return 0;
}
    