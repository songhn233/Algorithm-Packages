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
const int maxn=2050;
int n,m,l,r;
int a[maxn],b[maxn];
int main()
{
  cin>>n>>m>>l>>r;
  rep(i,1,n) 
  {
    int x,y;rd(x),rd(y);
    rep(j,x,y) a[j]=1;
  }
  rep(i,1,m)
  {
    int x,y;rd(x),rd(y);
    rep(j,x,y) b[j]=1;
  }
  int ans=0;
  rep(i,l,r)
  {
    rep(j,i,1000) 
    {
      if(a[j]&&b[j-i]) 
      {
        ans++;
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}