#include <iostream>

using namespace std;
string s;
int main()
{
    cin >> s;
    int d = 0;
    for (int i=0; i<s.size(); i++)
    {
        char _check;
        if (s[i] == 'a') _check = 'z';
        else
        _check = (int)s[i] - 1;
        if (_check < s[i])
        {
            s[i] = _check;
            d++;
        }
        else
        {
            if (d != 0) break;
        }
    }
    if (d == 0)
    {
        if (s[s.size()-1] == 'a') s[s.size()-1] = 'z';
        else s[s.size()-1] = (int)s[s.size()-1] -1;
    }
    cout << s;
    return 0;
}
    