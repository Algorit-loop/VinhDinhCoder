#include <iostream>

using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    //s = s + "@";
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == s[i-1])
        {
            char _check1 , _check2;
            if (s[i] == 'a') _check1 = 'z';
            else _check1 = (int)s[i] - 1;
            if (s[i] == 'z') _check2 = 'a';
            else _check2 = (int)s[i] + 1;
            if (_check1 == s[i+1]) s[i] = _check2;
            if (_check2 == s[i+1]) s[i] = _check1;
            if (_check1 != s[i+1] && _check2 != s[i+1]) s[i] = _check1;
        }
    }
    //s.erase(s.size()-1,1);
    cout << s;
    return 0;
}
    