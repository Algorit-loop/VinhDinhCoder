#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    int n,a[100000];
    cin >>n;
    for (int i=1;i<=n;i++) cin >>a[i];
    int sum=0,d1=0;
    for (int i=1;i<=n;i++)
    {
        sum=sum+a[i];
        if (a[i]==1) d1++;
    }
    if (d1>=1)
    {
        int maxn=200000,prime[maxn];
        for (int i=2;i<=maxn;i++) prime[i]=1;
        for (int i=2;i<=maxn;i++)
            if(prime[i]==1)
                for (int j=2;j<=maxn/i;j++) prime[i*j]=0;
        for (int i=3;i<=maxn;i++) prime[i]=prime[i-1]+prime[i];
        cout <<prime[sum];
    }
    else cout <<1;
}
    