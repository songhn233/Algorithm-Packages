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
int n,m;
const int maxn=300050;
ll num;
struct node{
  ll u,v,w;
}ans[maxn];
struct edge{
  ll val,id;
  bool operator<(const edge&t) const{
    return val<t.val;
  }
}d[maxn];
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++) d[i].id=i;
  for(int i=1;i<=m;i++)
  {
    ll x,y,z;rd(x),rd(y),rd(z);
    d[x].val-=z,d[y].val+=z;
  }
  sort(d+1,d+n+1);
  int l=1,r=n;
  while(l<r)
  {
    if(d[l].val==0&&d[r].val==0) break;
    ll temp=min(-d[l].val,d[r].val);
    d[l].val+=temp;
    d[r].val-=temp;
    ans[++num]={d[l].id,d[r].id,temp};
    if(d[l].val==0) l++;
    if(d[r].val==0) r--;
  }
  cout<<num<<endl;
  for(int i=1;i<=num;i++) cout<<ans[i].u<<" "<<ans[i].v<<" "<<ans[i].w<<endl;
  return 0;
}