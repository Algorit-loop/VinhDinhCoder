#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    int maxn=300000;
    long long n,k,a[maxn],f[maxn],sum[maxn],b[maxn],c[maxn];
    cin >>n>>k;
    for (int i=1;i<=n;i++) cin >>a[i];
    for (int i=1;i<=k;i++) cin >> b[i]>>c[i];
    for (int i=1;i<1000;i++) f[i]=0,sum[i]=0;
    for (int i=1;i<=n;i++)
    {
        int j=i;
        while (j<=n)
        {
            f[j]=f[j]+a[i];
            j=j+(j&-j);
        }
    }
    /*for (int i=1;i<=n;i++)
    {
        int j=i;
        while (j>=1)
        {
            sum[i]=sum[i]+f[j];
            j=j-(j&-j);
        }
    }*/
    for (int p=1;p<=k;p++)
    {
        int j=b[p],i=c[p];
        long long result=0;
        while (i>=j)
            if (i-(i&-i)>=j)
            {
                result = result +f[i];
                i=i-(i&-i);
            }
            else
            {
                result = result + a[i];
                i=i-1;
            }
        cout <<result<<endl;
    }
    //for (int i=1;i<=n;i++) cout <<sum[i]<<" ";
}
    