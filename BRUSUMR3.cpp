#include <iostream>

using namespace std;
const int maxN = 2000;
long long a[maxN][maxN],dp[maxN][maxN];
int n,m,k,x,y,u,v,c;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) a[i][j] = 1;
    for (; k>=1; k--)
    {
        cin >> x >> y >> u >> v >> c;
        dp[x][y] = dp[x][y] + c;
        dp[x][v+1] = dp[x][v+1] - c;
        dp[u+1][y] = dp[u+1][y] - c;
        dp[u+1][v+1] = dp[u+1][v+1] + c;
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            dp[i][j] = dp[i][j-1] + dp[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j];
    /*for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout << dp[i][j] <<" ";
        cout << "\n";
    }*/
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) a[i][j] = a[i][j] + dp[i][j];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
    