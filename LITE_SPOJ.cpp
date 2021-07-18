#include <iostream>
#define ll long long
using namespace std;
const int maxN = 1e5+10;
int n,m;
int Tree[4*maxN],lazy[4*maxN];
void lazy_up(int k,int L,int R)
{
    if (lazy[k] % 2 != 0)
    {
        Tree[k] = R - L + 1 - Tree[k];
        if (L < R)
        {
            lazy[2*k] += lazy[k];
            lazy[2*k+1] += lazy[k];
        }
        lazy[k] = 0;
    }
}
void update(int k,int L,int R,int u,int v)
{
    lazy_up(k,L,R);
    if (L > v || R < u) return;
    if (L >= u && R <= v)
    {
        lazy[k] += 1;
        lazy_up(k,L,R);
        return;
    }
    int mid = (L + R) >> 1;
    update(2*k,L,mid,u,v);
    update(2*k+1,mid+1,R,u,v);
    Tree[k] = Tree[2*k] + Tree[2*k+1];
}
ll query(int k,int L,int R,int u,int v)
{
    lazy_up(k,L,R);
    if (L > v || R < u) return 0;
    if (L >= u && R <= v)
    {
        return Tree[k];
    }
    int mid = (L + R) >> 1;
    return query(2*k,L,mid,u,v) + query(2*k+1,mid+1,R,u,v);
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int p,x,y;
        cin >> p >> x >> y;
        if (p == 0)
        {
            update(1,1,n,x,y);
        }
        else
        {
            cout << query(1,1,n,x,y) <<"\n";
        }
    }
    return 0;
}