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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=150;
const int maxm=10005;
int n,ans,num,fa[maxn];
struct node{
    int u,v,w;
    bool operator<(const node&t) const{
        return w<t.w;
    }
}e[maxm];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
void kruskal()
{
    sort(e+1,e+num+1);
    for(int i=1;i<=num;i++)
    {
        int x=e[i].u,y=e[i].v;
        x=get(x),y=get(y);
        if(x==y) continue;
        fa[x]=y;
        ans+=e[i].w;
    }
    printf("%d\n",ans);
}
int main()
{
    while(cin>>n)
    {
        if(!n) break;
        ans=num=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n*(n-1)/2;i++)
        {
            int x,y,z,p;
            read(x),read(y),read(z),read(p);
            if(p==1)
            {
                x=get(x),y=get(y);
                fa[x]=y;
            }
            else e[++num]={x,y,z};
        }
        kruskal();
    }
    return 0;
}
