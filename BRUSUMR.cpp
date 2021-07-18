#include <iostream>

using namespace std;
const int maxN = 800;
long long a[maxN][maxN];
int n,m,k;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) cin >> a[i][j];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            a[i][j] = a[i][j-1] + a[i][j];
    }
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=n; i++)
            a[i][j] = a[i-1][j] + a[i][j];
    }
    long long res = 0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (i - k >= 0 && j - k >= 0)
                res = max(res,a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k]);
    }
    /*cout <<"==========================\n";
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }*/
    cout << res;
    return 0;
}
    