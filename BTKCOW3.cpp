#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s="",f[1048577];
int a[100],x=0,n,p=0,d=0;
ll cnt1=0,cnt2=0;
void _Check()
{
    if (cnt1==cnt2)
    {
        //x++;
        //f[x]=s;
        p=max(p,d);
    }
}
void _Choose(int i)
{
    for (int j=1;j<=3;j++)
    {
        if (j==1)
        {
            cnt1=cnt1+a[i];
            //s=s+'1';
            d++;
        }
        if (j==2)
        {
            cnt2=cnt2+a[i];
            //s=s+'2';
            d++;
        }
        if (i<n) _Choose(i+1);
        if (i==n) _Check();
        if (j==1) cnt1=cnt1-a[i]//,s.erase(s.length()-1,1)
            ,d--;
        if (j==2) cnt2=cnt2-a[i]//,s.erase(s.length()-1,1)
            ,d--;
    }
}
int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    cin >>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    _Choose(1);
    /*if (x==0) cout <<-1;
    else
    for (int i=1;i<=x;i++) cout <<f[i]<<endl;*/
    cout <<n-p;
}
    