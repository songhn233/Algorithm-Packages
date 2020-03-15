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
const int maxn=100050;
ll T,n,x[maxn],r[maxn];
int main()
{
  cin>>T;
  while(T--)
  {
    read(n);
    for(int i=1;i<=n;i++) read(x[i]),read(r[i]);
    ll ans=0;
    int flag=0;
    for(int i=1;i<n;i++)
    {
      int nex=-1;
      int idx=upper_bound(x+i+1,x+n+1,x[i]+r[i])-x;
      idx--;
      if(idx==i)
      {
        flag=1;
        break;
      }
      if(x[i]+r[i]>=x[idx]&&x[idx]-r[idx]<=x[i])
      {
        nex=idx;
      }
      else
      {
        for(int j=idx;j>=i+1;j--)
        {
          if(x[i]+r[i]>=x[j]&&x[j]-r[j]<=x[i])
          {
            nex=j;
          }
        }
      }
      if(nex==-1)
      {
        flag=1;
        break;
      }
      ans+=3*(x[nex]-x[i]);
      i=nex-1;
    }
    if(flag) printf("-1\n");
    else printf("%lld\n",ans);
  }
  return 0;
}