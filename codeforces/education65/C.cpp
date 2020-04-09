#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=500050;
int n,m;
int fa[maxn],siz[maxn];
int get(int x){if(x!=fa[x])fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
    x=get(x),y=get(y);
    if(x==y) return ;
    fa[x]=y;
    siz[y]+=siz[x];
}
int main()
{
    cin>>n>>m;
    rep(i,1,n) fa[i]=i,siz[i]=1;
    rep(i,1,m)
    {
        int k;rd(k);
        int x,y;
        if(k) rd(x);
        rep(j,1,k-1) 
        {
            rd(y);
            merge(x,y);
        }
    }
    rep(i,1,n)
    {
        printf("%d ",siz[get(i)]);
    }
    cout<<endl;
    return 0;
}