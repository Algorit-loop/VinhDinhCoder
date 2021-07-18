#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 1e5;
int n,m;
int Tree[4*maxN],lazy[4*maxN];
int a[50000],b[50000];
set<int> mymap;
vector<int> V;
void lazy_up(int k,int L,int R)
{
    if (lazy[k] != 0)
    {
        Tree[k] = lazy[k];
        if (L < R)
        {
            lazy[2*k] = lazy[k];
            lazy[2*k+1] = lazy[k];
        }
        lazy[k] = 0;
    }
}
void update(int k,int L,int R,int u,int v,int i)
{
    lazy_up(k,L,R);
    if (L > v || R < u) return;
    if (L >= u && R <= v)
    {
        lazy[k] = i;
        lazy_up(k,L,R);
        return;
    }
    int mid = (L + R) >> 1;
    update(2*k,L,mid,u,v,i);
    update(2*k+1,mid+1,R,u,v,i);
}
ll query(int k,int L,int R,int pos)
{
    lazy_up(k,L,R);
    if (L == R && R == pos)
    {
        return Tree[k];
    }
    int mid = (L + R) >> 1;
    if (pos > mid) return query(2*k+1,mid+1,R,pos);
    else return query(2*k,L,mid,pos);
}
int main()
{
    int t;
    cin >> t;
    for (; t>0; t--)
    {
        V.clear();
        mymap.clear();
        n = 0;
        cin >> m;
        for (int i=1; i<=m; i++)
        {
            cin >> a[i] >> b[i];
            V.push_back(a[i]);
            V.push_back(b[i]);
        }
        sort(V.begin(),V.end());
        V.resize(unique(V.begin(),V.end()) - V.begin());
        for (int i=1; i<=m; i++)
        {
            a[i] = lower_bound(V.begin(),V.end(),a[i]) - V.begin() + 1;
            b[i] = lower_bound(V.begin(),V.end(),b[i]) - V.begin() + 1;
            //cout << a[i] << " " << b[i] << "\n";
            n = max(n , b[i]);
        }
        //for (int i=1; i<=4*n; i++) Tree[i] = 0 , lazy[i] = 0;
        memset(Tree,0,sizeof(Tree));
        memset(lazy,0,sizeof(lazy));
        for (int i=1; i<=m; i++)
            update(1,1,n,a[i],b[i],i);
        for (int i=1; i<=n; i++)
        {
            int p = 1;
            p = query(1,1,n,i);
            if (p > 0) mymap.insert(p);
            //cout << p << "\n";
        }
        cout << mymap.size() << "\n";
    }
    return 0;
}