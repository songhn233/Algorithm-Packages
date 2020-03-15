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
const int maxn=10050;
int n,m,a[maxn],vis[maxn],v[maxn],pre[maxn];
int tim;
void bfs()
{
  queue<int> q;
  while(!q.empty()) q.pop();
  mst(v,-1);
  mst(pre,-1);
  for(int i=1;i<10;i++)
  {
    if(vis[i]) continue;
    if(v[i%n]!=-1) continue;
    q.push(i%n);
    v[i%n]=i;
  }
  while(!q.empty())
  {
    int u=q.front();q.pop();
    if(u==0)
    {
      int temp=u;
      vector<int> ans;ans.clear();
      while(temp!=-1)
      {
        ans.push_back(v[temp]);
        temp=pre[temp];
      }
      for(int i=(int)ans.size()-1;i>=0;i--) cout<<ans[i];
      cout<<endl;
      return ;
    }
    for(int i=0;i<10;i++)
    {
      if(vis[i]) continue;
      int t=(u*10+i)%n;
      //cout<<t<<"---"<<i<<endl; 
      if(v[t]==-1)
      {
        v[t]=i;
        pre[t]=u;
        q.push(t);
      }
    }
  }
  cout<<"-1"<<endl;
}
int main()
{
  while(~scanf("%d%d",&n,&m))
  {
    tim++;
    mst(vis,0);
    for(int i=1;i<=m;i++) read(a[i]),vis[a[i]]=1;
    printf("Case %d: ",tim);
    bfs();
  }
  return 0;
}