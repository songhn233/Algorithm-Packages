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
const int maxn=100050;
int n,T,r[maxn],a[maxn],s[maxn];
struct node{
  int v,w,nex;
}e[maxn];
int head[maxn],num;
void add(int u,int v,int w)
{
  e[++num].nex=head[u];
  e[num].v=v;e[num].w=w;
  head[u]=num;
}
int d[maxn],vis[maxn];
bool calc(int mid)
{
  mst(head,0);mst(d,0xcf);mst(vis,0);num=0;
  rep(i,0,23) add(i,i+1,0),add(i+1,i,-a[i]);
  rep(i,8,24) add(i-8,i,r[i-1]);
  rep(i,1,7) add(i+16,i,r[i-1]-mid);
  add(0,24,mid);add(24,0,-mid);
  queue<int> q;
  while(!q.empty()) q.pop();
  q.push(0);vis[0]=1;d[0]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    vis[u]=0;
    if(u==24&&d[24]>mid) return false;
    for(int i=head[u];i;i=e[i].nex)
    {
      int v=e[i].v;
      if(d[v]<d[u]+e[i].w)
      {
        d[v]=d[u]+e[i].w;
        if(!vis[v]) q.push(v);
      }
    }
  }
  return (d[24]<=mid);
}
int main()
{
  cin>>T;
  while(T--)
  {
    rep(i,0,23) rd(r[i]);
    cin>>n;
    int l=0,r=n+1;
    rep(i,1,n)
    {
      int x;rd(x);
      a[x]++;
    }
    while(l<r)
    {
      int mid=l+r>>1;
      if(calc(mid)) r=mid;
      else l=mid+1;
    }
    if(r==n+1) puts("No Solution");
    else cout<<l<<endl;
  }
  return 0;
}