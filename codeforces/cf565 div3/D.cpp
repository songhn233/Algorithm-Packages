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
const int N=2800000;
int n,b[maxn];
int num,vis[N],prime[N];
map<int,int> mp;
map<int,int> mmp;
vector<int> ans;
void is_prime(int n)
{
  for(int i=2;i<=n;i++)
  {
    if(!vis[i]) prime[++num]=i,mp[i]=1;
    for(int j=1;prime[j]<=n/i;j++)
    {
      vis[prime[j]*i]=1;
      if(i%prime[j]==0) break;
    }
  }
}
int calc(int x)
{
  int res=0;
  for(int i=2;i<=x/i;i++)
  {
    if(x%i==0) res=max(res,max(i,x/i));
  }
  return res;
}
int main()
{
  is_prime(2750131);
  cin>>n;
  n<<=1;
  rep(i,1,n) rd(b[i]),mmp[b[i]]++;
  sort(b+1,b+n+1);
  n=unique(b+1,b+n+1)-(b+1);
  dep(i,n,1)
  {
    if(mp[b[i]]) continue;
    for(int j=0;j<mmp[b[i]];j++)
    {
      ans.push_back(b[i]);
    }
    int t=calc(b[i]);
    mmp[t]-=mmp[b[i]];
  }
  rep(i,1,n)
  {
    if(mp[b[i]]==0) continue;
    for(int j=0;j<mmp[b[i]];j++)
    {
      ans.push_back(b[i]);
    }
    mmp[prime[b[i]]]-=mmp[b[i]];
  }
  rep(i,0,(int)ans.size()-1) cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}