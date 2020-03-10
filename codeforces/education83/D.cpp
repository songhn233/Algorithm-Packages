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
const ll p=998244353;
const ll maxn=200050;
ll n,m,fac[maxn];
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
ll c(ll m,ll n)
{
  return (fac[n]%p*ksm(fac[m],p-2)%p*ksm(fac[n-m],p-2)%p)%p;
}
int main()
{
  cin>>n>>m;
  if(n==2) puts("0");
  else
  {
    fac[0]=fac[1]=1;
    for(int i=2;i<=m;i++) fac[i]=(fac[i-1]*i)%p;
    ll ans=0;
    cout<<(c(n-1,m)*(n-2)%p*ksm(2,n-3)%p)%p<<endl;
  }
  return 0;
}