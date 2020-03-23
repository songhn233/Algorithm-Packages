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
int T,n,m,in[maxn];
vector<int> e[maxn];
vector<int> ans;
priority_queue<int> pq;
int main()
{
  cin>>T;
  while(T--)
  {
    rd(n),rd(m);
    mst(in,0);ans.clear();
    while(!pq.empty()) pq.pop();
    rep(i,0,n) e[i].clear();
    rep(i,1,m)
    {
      int x,y;rd(x),rd(y);
      e[y].push_back(x);
      in[x]++;
    }
    rep(i,1,n) if(!in[i]) pq.push(i);
    while(!pq.empty())
    {
      int u=pq.top();pq.pop();
      ans.push_back(u);
      rep(i,0,(int)e[u].size()-1)
      {
        int v=e[u][i];in[v]--;
        if(!in[v]) pq.push(v);
      }
    }
    dep(i,(int)ans.size()-1,0)
    {
      if(i) printf("%d ",ans[i]);
      else printf("%d\n",ans[i]);
    }
  }
  return 0;
}