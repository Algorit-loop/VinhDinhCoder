#include <iostream>
#include <vector>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
pair <int,int> a[N];
long long f[N];
int p = 0 , q = 0 , n , u[N] , m[N];
pair <int,long long> bit[N];
vector <int> V[N];
void update(int x,int val){
    for (; x >= 1; x -= x&(-x)){
        bit[x].fi++;
        bit[x].second += val;
    }
}
pair <int,long long> getbit(int x){
    pair <int,long long> res = {0,0};
    for (; x <= q; x += x&(-x)){
        res.fi += bit[x].fi;
        res.se += bit[x].se;
    }
    return res;
}
int check (int x){
    int L = 1 , R = q , pos = q + 1;
    while (L <= R){
        int mid = (L + R) >> 1;
        pair <int,long long> hs = getbit(mid);
        if (hs.fi >= x){
            L = mid + 1;
            pos = mid;
        }
        else
            R = mid - 1;
    }
    return pos;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
        u[a[i].fi]++;
        p = max(p,a[i].fi);
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
        m[a[i].fi] += a[i].se;
        V[a[i].fi].push_back(a[i].se);
        q = max(q,a[i].se);
    }
    for (int i = 1; i <= p; i++) f[i] = f[i - 1] + m[i];
    long long sumque = 0 , ans = 1e18;
    for (int i = 1; i <= p; i++){
        if (u[i] > 0){
            long long tmp = f[p] - f[i];
            int c = check(u[i] - 1);
            pair <int,long long> sp = getbit(c);
            long long cp = f[i - 1] - (sp.second - 1LL * c * max(0,sp.first - (u[i] - 1)));
            ans = min(ans,cp + tmp);
            for (auto x : V[i]) update(x,x);
        }
    }
    cout << ans;
    return 0;
}
