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
const int maxn=100010;
const int maxm=400010;
int n,m,fa[maxn],cnt[maxn],ans,pan;
int num,head[maxn],vis[maxn];
vector<int> e[maxn];
// struct node{
//     int v,nex;
//     // bool operator<(const node&t) const{
//     //     if(max(u,v)<max(t.u,t.v)) return true;
//     //     else return (min(u,v)<min(t.u,t.v));
//     // }
// }e[maxm];
int findx(int x){if(x!=fa[x])fa[x]=findx(fa[x]);return fa[x];}
void kruskal()
{
    for(int i=1;i<=n;i++)
    {
        if(pan>=n-1) break;
        sort(e[i].begin(),e[i].end());
        for(int j=0;j<e[i].size();j++)
        {
            if(pan>=n-1) break;
            int v=e[i][j];
            int x=i,y=v;
            int xx=findx(x),yy=findx(y);
            if(xx==yy) continue;
            fa[xx]=yy;
            pan++;
            cnt[x]++;cnt[y]++;
            ans=max(ans,max(cnt[x],cnt[y]));
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) fa[i]=i;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        e[y].push_back(x);
    }
    kruskal();
    printf("%d\n",ans);
    return 0;
}