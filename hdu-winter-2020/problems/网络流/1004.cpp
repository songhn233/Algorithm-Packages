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
const int maxn=200050;
const int N=25;
int head[maxn],num=1,d[maxn];
int s,t;
struct node{
  int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
  e[++num].nex=head[u];
  e[num].v=v;e[num].w=w;
  head[u]=num;
  e[++num].nex=head[v];
  e[num].v=u;e[num].w=0;
  head[v]=num;
}
bool bfs()
{
  memset(d,0,sizeof(d));
  queue<int> q;
  q.push(s);d[s]=1;
  while(!q.empty())
  {
      int u=q.front();q.pop();
      for(int i=head[u];i;i=e[i].nex)
      {
          int v=e[i].v;
          if(!e[i].w||d[v]) continue;
          d[v]=d[u]+1;
          q.push(v);
          if(v==t) return true;
      }
  }
  return false;
}
int dinic(int u,int flow)
{
  if(u==t) return flow;
  int rest=flow,temp;
  for(int i=head[u];i&&rest;i=e[i].nex)
  {
      int v=e[i].v;
      if(!e[i].w||d[v]!=d[u]+1) continue;
      temp=dinic(v,min(rest,e[i].w));
      if(!temp) d[v]=0;
      e[i].w-=temp;
      e[i^1].w+=temp;
      rest-=temp;
  }
  return flow-rest;
}
int T,n,m,nn;
string a[N],c[N];
bool calc(int x,int y)
{
  if(x-m<1||x+m>n) return true;
  if(y-m<1||y+m>nn) return true;
  return false;
}
int main()
{
  cin>>T;
  for(int tim=1;tim<=T;tim++)
  {
    int sum=0;
    num=1;mst(head,0);
    read(n),read(m);
    for(int i=1;i<=n;i++) cin>>a[i],a[i]=" "+a[i];
    for(int i=1;i<=n;i++) cin>>c[i],c[i]=" "+c[i];
    nn=(int)a[1].size()-1;
    s=0,t=2*n*nn+1;
    for(int i=1;i<=n;i++) for(int j=1;j<=nn;j++) add((i-1)*nn+j,n*nn+(i-1)*nn+j,a[i][j]-'0');
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=nn;j++)
      {
        if(c[i][j]=='L') add(s,(i-1)*nn+j,1),sum++;
      }
    }
    for(int x1=1;x1<=n;x1++)
    {
      for(int y1=1;y1<=nn;y1++)
      {
        if(calc(x1,y1)) add(n*nn+(x1-1)*nn+y1,t,inf);
        for(int x2=1;x2<=n;x2++)
        {
          for(int y2=1;y2<=nn;y2++)
          {
            if(x1==x2&&y1==y2) continue;
            if(abs(x1-x2)+abs(y1-y2)<=m)
            {
              add(n*nn+(x1-1)*nn+y1,(x2-1)*nn+y2,inf);
            }
          }
        }
      }
    }
    int maxflow=0;
    while(bfs()){maxflow+=dinic(s,inf);}
    if(maxflow==sum) printf("Case #%d: no lizard was left behind.\n",tim);
    else if(sum-maxflow==1) printf("Case #%d: %d lizard was left behind.\n",tim,sum-maxflow);
    else printf("Case #%d: %d lizards were left behind.\n",tim,sum-maxflow);
  }
  return 0;
}