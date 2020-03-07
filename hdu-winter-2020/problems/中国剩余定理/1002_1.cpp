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
const int maxn=20;
ll T,N,m;
ll a[maxn],b[maxn];
ll exgcd(ll &x,ll &y,ll a,ll b)
{
  if(!b)
  {
    x=1,y=0;
    return a;
  }
  ll d=exgcd(x,y,b,a%b);
  ll temp=x;
  x=y;
  y=temp-a/b*y;
  return d;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>N>>m;
    for(int i=1;i<=m;i++) read(a[i]);
    for(int i=1;i<=m;i++) read(b[i]);
    ll t1=b[1],t2=a[1];
    if(t1==0) t1=a[1];
    ll x,y;
    int flag=0;
    for(int i=2;i<=m;i++)
    {
      ll temp=b[i]-t1;
      ll d=exgcd(x,y,t2,a[i]);
      if(temp%d)
      {
        puts("0");
        flag=1;
        break;
      }
      x*=temp/d;
      x=(x%(a[i]/d)+(a[i]/d))%(a[i]/d);
      t1=t1+x*t2;
      t2=lcm(t2,a[i]);
      t1=(t1%t2+t2)%t2;
    }
    t1=(t1%t2+t2)%t2;
    if(flag) continue;
    if(t1==0) cout<<(N-t1)/t2<<endl;
    else if(N-t1<0) puts("0");
    else cout<<(N-t1)/t2+1<<endl;
  }
  return 0;
}