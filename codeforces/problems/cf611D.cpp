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
const int maxn=400050;
map<int,bool> vis;
ll n,m,a[maxn],ans;
queue<int> q;
vector<int> res;
int main()
{
  cin>>n>>m;
  rep(i,1,n) rd(a[i]),vis[a[i]]=true;
  rep(i,1,n) 
  {
    if(!vis[a[i]-1]) q.push(a[i]-1),vis[a[i]-1]=true;
    if(!vis[a[i]+1]) q.push(a[i]+1),vis[a[i]+1]=true;
  }
  int flag=0;
  ll idx=1,tot=0;
  while(!q.empty())
  {
    if(flag) break;
    int v=q.size();
    rep(temp,1,v)
    {
      int u=q.front();q.pop();
      tot++;ans+=idx;res.push_back(u);
      if(tot>=m)
      {
        flag=1;
        break;
      }
      if(!vis[u-1]) q.push(u-1),vis[u-1]=true;
      if(!vis[u+1]) q.push(u+1),vis[u+1]=true;
    }
    idx++;
  }
  cout<<ans<<endl;
  rep(i,0,(int)res.size()-1) cout<<res[i]<<" ";
  cout<<endl;
  return 0;
}