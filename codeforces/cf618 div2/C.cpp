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
ll n,a[maxn],b[maxn];
ll pre[maxn],nex[maxn];
int main()
{
  cin>>n;
  rep(i,1,n) rd(a[i]);
  if(n==1)
  {
    cout<<a[1]<<endl;
    return 0;
  }
  rep(i,1,n)
  {
    rep(j,0,30)
    {
      if(a[i]>>j&1) continue;
      else b[i]+=(1ll<<j);
    }
  }
  pre[1]=b[1];
  rep(i,2,n) pre[i]=pre[i-1]&b[i];
  nex[n]=b[n];
  dep(i,n-1,1) nex[i]=nex[i+1]&b[i];
  ll ans=0,idx=0;
  rep(i,1,n)
  {
    if(i==1) 
    {
      if((a[1]&nex[2])>ans)
      {
        ans=a[1]&nex[2];
        idx=1;
      }
    }
    else if(i==n) 
    {
      if((a[n]&pre[i-1])>ans)
      {
        ans=a[n]&pre[i-1];
        idx=n;
      }
    }
    else 
    {
      if((a[i]&pre[i-1]&nex[i+1])>ans)
      {
        ans=a[i]&pre[i-1]&nex[i+1];
        idx=i;
      }
    }
  }
  if(idx)
  {
    cout<<a[idx]<<" ";
    rep(i,1,n) 
    {
      if(i==idx) continue;
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  else
  {
    rep(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
  }
  
  return 0;
}