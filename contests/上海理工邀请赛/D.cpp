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
const int maxn=400010;
int n,m,fa[maxn],cnt[maxn],ans,num;
struct node{
    int u,v;
    PII w;
    bool operator<(const node&t) const{
        int a=w.first,b=w.second;
        int c=t.w.first,d=t.w.second;
        if(a<b) swap(a,b);
        if(c<d) swap(c,d);
        if(a==c) return b<d;
        else return a<c;
    }
}e[maxn];
int findx(int x){if(x!=fa[x])fa[x]=findx(fa[x]);return fa[x];}
void kruskal()
{
    for(int i=1;i<=m;i++)
    {
        int x=e[i].u,y=e[i].v;
        int xx=findx(x),yy=findx(y);
        if(xx==yy) continue;
        fa[xx]=yy;
        cnt[x]++,cnt[y]++;
    }
}
int main()
{
    cin>>n>>m;
    rep(i,1,n) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;rd(x),rd(y);
        e[++num]={x,y,make_pair(x,y)};
    }
    sort(e+1,e+m+1);
    kruskal();
    int ans=0;
    rep(i,1,n) ans=max(ans,cnt[i]);
    cout<<ans<<endl;
    return 0;
}