#include <iostream>

using namespace std;

int main()
{
ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    int dp[1000000],cd[1000000],k,res=0;
    dp[1]=0;
    cin >>k;
    string s;
    cin >>s;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='1') dp[i+1]=dp[i]+1; else dp[i+1]=dp[i];
    }
    //for (int i=1;i<=s.length();i++) cout <<dp[i]<<' ';
    //cout <<dp[s.length()]<<endl;
    for (int i=1;i<=s.length();i++) cd[dp[i]]++;
    //for (int i=0;i<=dp[s.length()];i++) cout <<cd[i]<<' '; cout <<endl;

    if (dp[s.length()]<k) cout << 0;
    else
    {
        if (cd[0]==0) res=res+cd[k];else res=res+cd[k]*(cd[0]+1);
        for (int i=k+1;i<=dp[s.length()];i++)
        res=res+cd[i]*cd[i-k];
        cout <<res;
    }
}
    