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
const int maxn=200050;
int n,a[maxn];
int minx[maxn],maxx[maxn];
int ans,l,r;
int main()
{
  cin>>n;
  l=inf,r=-inf;
  rep(i,1,n)
  {
    int x;rd(x);
    a[x]++;
    l=min(l,x),r=max(r,x);
  }
  rep(i,1,n) minx[i]=a[i],maxx[i]=a[i];
  ans=0;
  rep(i,l,r)
  {
    if(!maxx[i]) continue;
    if(maxx[i-1]==0) continue;
    maxx[i]+=maxx[i-1],maxx[i-1]=0;
    maxx[i]+=maxx[i+1],maxx[i+1]=0;
  }
  rep(i,0,n+1) if(maxx[i]) ans++;
  cout<<ans<<" ";
  rep(i,1,n)
  {
    if(minx[i]>1)
    {
      if(!minx[i-1]) minx[i-1]=1,minx[i]--;
    }
    if(minx[i]>1)
    {
      if(!minx[i+1]) minx[i+1]=1,minx[i]--;
    }
  }
  ans=0;
  rep(i,0,n+1) if(minx[i]) ans++;
  cout<<ans<<endl;
  return 0;
}