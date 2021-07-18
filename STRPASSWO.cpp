#include <iostream>

using namespace std;
const int maxN = 1e6 + 10;
string s;
int number[maxN],lower[maxN],upper[maxN];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    s = "!" + s;
    number[0] = 0 ;
    lower[0] = 0;
    upper[0] = 0;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') number[i] = number[i-1] + 1;
            else number[i] = number[i-1];
        if (s[i] >= 'a' && s[i] <= 'z') lower[i] = lower[i-1] + 1;
            else lower[i] = lower[i-1];
        if (s[i] >= 'A' && s[i] <= 'Z') upper[i] = upper[i-1] + 1;
            else upper[i] = upper[i-1];
    }
    int j = 1;
    long long ans = 0;
    bool RUN , _check;
    for (int i=1; i<s.size(); i++)
    {
        RUN = true;
        while (RUN == true)
        {
            _check = false;
            if (number[i] - number[j-1] > 0 &&
                lower[i] - lower[j-1] > 0 &&
                upper[i] - upper[j-1] > 0) _check = true;
            if (_check == true && i - j + 1 >= 6)
            {
                ans = ans + s.size() - i;
                j++;
            }
            else RUN = false;
        }
    }
    cout << ans;
    return 0;
}
    