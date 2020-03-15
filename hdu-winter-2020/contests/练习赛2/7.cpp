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
const int maxn=2050;
int n,m,k,vis[maxn][maxn];
int ans=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
  if(x<1||x>n||y<1||y>m) return false;
  if(vis[x][y]) return false;
  return true;
}
void bfs(int x,int y)
{
  queue<PII> q;
  q.push(make_pair(x,y));
  vis[x][y]=1;
  while(!q.empty())
  {
    PII u=q.front();
    q.pop();
    int x=u.first,y=u.second;
    for(int i=0;i<4;i++)
    {
      int tx=x+dx[i],ty=y+dy[i];
      if(!calc(tx,ty)) continue;
      vis[tx][ty]=1;
      q.push(make_pair(tx,ty));
    }
  }
}
int main()
{
  cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    int x,y;read(x),read(y);
    vis[x][y]=1;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(!vis[i][j])
      {
        ans++;
        bfs(i,j);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}