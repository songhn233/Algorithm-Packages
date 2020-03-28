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
const int maxn=1050;
const ll p=998244353;
int n;
ll x[maxn],y[maxn];
ll ksm(ll a,ll b)
{
  ll res=1%p;
  while(b)
  {
    if(b&1) res=(res*a)%p;
    a=(a*a)%p;
    b>>=1;
  }
  return res;
}
int main()
{
  cin>>n;
  rep(i,1,n) rd(x[i]),rd(y[i]);
  ll ans=0;
  rep(i,1,n)
  {
    rep(j,i+1,n)
    {
      ll temp=abs(x[i]-x[j])+abs(y[i]-y[j]);
      ans=(ans+temp*(n-2))%p;
    }
  }
  cout<<ans<<endl;
  return 0;
}