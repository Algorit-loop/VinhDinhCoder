#include <bits/stdc++.h>
using namespace std;

int n;
struct st{
    int x, y, z;
};
st a[16002 * 3], b[16002];
long long f[16002 * 3];

bool cmp(st &t1, st &t2){
    if (t1.x != t2.x) return t1.x < t2.x;
    if (t1.y != t2.y) return t1.y < t2.y;
    if (t1.z != t2.z) return t1.z < t2.z;
    return false;
}

bool check(st t1, st t2){
    return (t1.x > t2.x && t1.y > t2.y);
}

void hdl(){
    for (int i=0;i<n;i++){
        int tmin1 = min(b[i+1].x, b[i+1].y);
        int tmax1 = max(b[i+1].x, b[i+1].y);

        a[i*3+1].x = tmin1;
        a[i*3+1].y = tmax1;
        a[i*3+1].z = b[i+1].z;

        int tmin2 = min(b[i+1].y, b[i+1].z);
        int tmax2 = max(b[i+1].y, b[i+1].z);
        a[i*3+2].x = tmin2;
        a[i*3+2].y = tmax2;
        a[i*3+2].z = b[i+1].x;

        int tmin3 = min(b[i+1].x, b[i+1].z);
        int tmax3 = max(b[i+1].x, b[i+1].z);
        a[i*3+3].x = tmin3;
        a[i*3+3].y = tmax3;
        a[i*3+3].z = b[i+1].y;
    }
    n*=3;
    sort(a+1, a+1+n, cmp);
    for (int i=0;i<=n;i++)
        f[i] = 0;
    long long res = 0;
    f[1] = a[1].z;
    for (int i=2;i<=n;i++){
        f[i] = a[i].z;
        for (int j=1;j<i;j++){
            if (check(a[i],a[j])) f[i] = max(f[i], f[j] + a[i].z);
        }
        res = max(res, f[i]);
    }

    cout<<res<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    n = 1;
    while (n != 0){
        cin>>n;
        if (n == 0) break;
        for (int i=1;i<=n;i++){
            cin>>b[i].x>>b[i].y>>b[i].z;
        }
        hdl();
    }

}