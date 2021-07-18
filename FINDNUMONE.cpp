#include <iostream>
#include <string>
using namespace std;
int F[1000000],DP[1000000],n,k;
int a[100009];
string s="";
string _chance(int h)
{
    string ans="";
    if (h==0) return "0";
    while (h>0)
    {
        ans=char(h%2+48)+ans;
        h/=2;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
        s=s+_chance(a[i]);
    //cout<<s<<"\n";
    int cnt=0;
    int l=-1,res=0,r=s.size();
    for (int i=0;i<r;i++)
    {
        if (i == r-1 || s[i] != s[i+1])
        {
            F[++cnt]=i-l;
            l = i;
            if (s[i] == '0') DP[cnt]=1;
            else DP[cnt]=0;
        }
    }
    l = 0; F[0] = 0; DP[0] = 0;
    for (int i=1;i<=cnt;i++)
    {
        F[i] += F[i-1];
        DP[i] += DP[i-1];
        while((l<i)&&(DP[i]>DP[l]+k)) l++;
        res=max(res,F[i]-F[l]);
    }
    cout << res;
    return 0;
}
    