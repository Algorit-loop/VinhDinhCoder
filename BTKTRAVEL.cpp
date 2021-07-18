#include <iostream>
#define llong long long
using namespace std;
const int maxN = 30;
llong c[30][30] , n;
int chon[30],a[maxN];
llong tong,res=1e18,road=1e18;
void ql(int x)
{
    for (int i=1; i<=n; i++)
    {
        if (chon[i] == 0 && tong + c[a[x-1]][i] < res)
        {
            a[x] = i;
            chon[i] = 1;
            tong = tong + c[a[x-1]][a[x]];
            if (x < n && tong + (n-x)*road < res) ql(x+1);
            if (x == n) res = min(res,tong);
            chon[i] = 0;
            tong = tong - c[a[x-1]][a[x]];
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> c[i][j] , road = min(road,c[i][j]);
    ql(1);
    cout << res;
    return 0;
}
    