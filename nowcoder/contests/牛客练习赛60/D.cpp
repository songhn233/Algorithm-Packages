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
const int maxn=1000010;
int exgcd(ll a,ll b,ll &x,ll &y)
{
  if(b==0){x=1,y=0;return a;}
  ll d=exgcd(b,a%b,x,y);
  ll z=x;x=y;y=z-a/b*y;
  return d;
}
ll a,b,c,k;
vector<PII> e[maxn];
ll d1[maxn],d2[maxn],vis[maxn],dis[maxn];
queue<int> q;
int main()
{
  cin>>a>>b>>c>>k;
  if(k%a==0)
  {
    cout<<k/a<<" "<<0<<" "<<0<<endl;
    return 0;
  }
  else if(k%b==0)
  {
    cout<<0<<" "<<k/b<<" "<<0<<endl;
    return 0;
  }
  else if(k%c==0)
  {
    cout<<0<<" "<<0<<" "<<k/c<<endl;
  }
  else
  {
    for(int i=0;i<a;i++) 
    {
      e[i].push_back(make_pair(b,(i+b)%a));
      e[i].push_back(make_pair(c,(i+c)%a));
    }
    q.push(0);
    mst(dis,0x3f);
    dis[0]=d1[0]=d2[0]=0;
    vis[0]=1;
    while(!q.empty())
    {
      int u=q.front();q.pop();
      vis[u]=0;
      for(int i=0;i<e[u].size();i++)
      {
        int v=e[u][i].second;
        if(dis[u]+e[u][i].first<dis[v])
        {
          dis[v]=dis[u]+e[u][i].first;
          d1[v]=d1[u];d2[v]=d2[u];
          if(e[u][i].first==b) d1[v]++;
          else d2[v]++;
          if(!vis[v]) q.push(v),vis[v]=1;
        }
      }
    }
    ll temp=k%a;
    k-=dis[temp];
    cout<<k/a<<" "<<d1[temp]<<" "<<d2[temp]<<endl;
  }
  return 0;
}