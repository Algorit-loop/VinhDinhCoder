#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    int maxn=200000,n,res=1;
    int a[maxn],dp[maxn];
    cin >>n;
    for (int i=1;i<=n;i++) cin >>a[i];
    dp[res]=a[1];
    for (int i=2;i<=n;i++)
        if (a[i]>dp[res])
        {
            res++;
            dp[res]=a[i];
        }
        else
        {
            int first=1,finish=res,location=0;
            while (first<=finish)
            {
                int mid=(first+finish)/2;
                if (dp[mid]<a[i])
                {
                    location=mid;
                    first=mid+1;
                }
                else finish=mid-1;
            }
            dp[location+1]=a[i];
        }
        cout << res;
}