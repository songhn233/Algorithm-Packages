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
int n,in[maxn];
vector<int> e[maxn];
map<PII,int> mp;
PII ans[maxn];
int main()
{
  cin>>n;
  rep(i,1,n-1)
  {
    int x,y;rd(x),rd(y);
    e[x].push_back(y);
    e[y].push_back(x);
    in[x]++,in[y]++;
    ans[i]=make_pair(x,y);
  }
  int t=-1;
  for(int i=1;i<=n;i++)
  {
    if(in[i]>=3)
    {
      t=i;
      break;
    }
  }
  if(t==-1) rep(i,1,n-1) cout<<i-1<<endl;
  else
  {
    rep(i,0,e[t].size()-1) mp[make_pair(t,e[t][i])]=mp[make_pair(e[t][i],t)]=1;
    int idx=e[t].size(),temp=0;
    rep(i,1,n-1)
    {
      int u=ans[i].first,v=ans[i].second;
      if(mp[make_pair(u,v)])
      {
        cout<<temp<<endl;
        temp++;
      }
      else cout<<idx<<endl,idx++;
    }
  }
  return 0;
}