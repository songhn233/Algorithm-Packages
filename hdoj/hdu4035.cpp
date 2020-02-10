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
const int maxn=20050;
const double eps=1e-9;
int T,n,du[maxn];
int head[maxn],num;
struct node{
    int v,nex;
}e[maxn];
void add(int u,int v)
{
    e[++num].nex=head[u];
    e[num].v=v;
    head[u]=num;
}
double a[maxn],b[maxn],c[maxn];
double k[maxn],E[maxn];
bool dfs(int u,int fa)
{
    double t=1-k[u]-E[u],m=du[u],temp=0.0;
    a[u]=k[u],b[u]=t/m,c[u]=t;
    int p=0;
    for(int i=head[u];i;i=e[i].nex)
    {
        p++;
        int v=e[i].v;
        if(v==fa) continue;
        if(!dfs(v,u)) return false;
        a[u]+=(t/m)*a[v];
        c[u]+=(t/m)*c[v];
        temp+=(t/m)*b[v];
    }
    if(p==0)
    {
        a[u]=k[u];b[u]=t;c[u]=t;
        return true;
    }
    if(fabs(1-temp)<eps) return false;
    a[u]/=(1-temp);
    b[u]/=(1-temp);
    c[u]/=(1-temp);
    return true;
}
int main()
{
    read(T);
    for(int t=1;t<=T;t++)
    {
        read(n);
        memset(head,0,sizeof(head));num=0;
        memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
        memset(du,0,sizeof(du));
        for(int i=1;i<n;i++)
        {
            int x,y;read(x),read(y);
            add(x,y),add(y,x);
            du[x]++,du[y]++;
        }
        for(int i=1;i<=n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            k[i]=x/100.0;E[i]=y/100.0;
        }
        printf("Case %d: ",t);
        if(!dfs(1,0)||(fabs(1.0-a[1])<eps)) printf("impossible\n");
        else printf("%.6lf\n",c[1]/(1.0-a[1]));
    }
    return 0;
}
