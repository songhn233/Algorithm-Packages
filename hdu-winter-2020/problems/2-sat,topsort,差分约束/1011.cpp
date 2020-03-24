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
const int maxn=550;
const int maxm=250050;
int n,m;
vector<int> e[maxn];
vector<int> ans;
int in[maxn];
int main()
{
  while(~scanf("%d%d",&n,&m))
  {
    ans.clear();
    mst(in,0);rep(i,0,n) e[i].clear();
    rep(i,1,m)
    {
      int x,y;rd(x),rd(y);
      in[y]++;
      e[x].push_back(y);
    }
    priority_queue<int,vector<int>,greater<int> > q;
    while(!q.empty()) q.pop();
    rep(i,1,n) if(!in[i]) q.push(i);
    while(!q.empty())
    {
      int u=q.top();q.pop();
      ans.push_back(u);
      rep(i,0,(int)e[u].size()-1)
      {
        int v=e[u][i];in[v]--;
        if(!in[v]) q.push(v);
      }
    }
    rep(i,0,(int)ans.size()-1)
    {
      if(i) printf(" %d",ans[i]);
      else printf("%d",ans[i]);
    }
    cout<<endl;
  }
  return 0;
}