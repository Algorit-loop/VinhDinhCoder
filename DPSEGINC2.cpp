#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

int main()
{
	ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    int maxn=300000;
    int n,a[maxn],dp[maxn],f[maxn];
    cin >>n;
    for (int i=1;i<=n;i++) cin >>a[i];
    int res=0,pos=0;
    for (int i=1;i<=n;i++)
    {
        int cnt=0;
        for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0) cnt=max(cnt,max(dp[j],dp[a[i]/j]));
        dp[a[i]]=cnt+1;
        f[i]=dp[a[i]];
        if (res<f[i])
        {
            res=f[i];
            pos=i;
        }
    }
    int pick[maxn],gtf=res;
    cout <<res<<endl;
    int k=1;
    pick[k]=pos;
    //for (int i=1;i<=n;i++) cout <<f[i]<<" "; cout <<endl;
    for (int i=pos-1;i>=1;i--)
        if ((f[i]>=gtf-1)&&(a[pick[k]]%a[i]==0))
            {
                gtf--;
                k++;
                pick[k]=i;
            }
    for (int i=k;i>=1;i--) cout <<pick[i]<<' ';
}
    