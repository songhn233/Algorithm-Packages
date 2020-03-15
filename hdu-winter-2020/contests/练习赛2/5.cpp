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
const int maxn=150;
int n,k,x[maxn],y[maxn];
ll ans[maxn],d[maxn],s[maxn];
int main()
{
  cin>>n>>k;
  mst(ans,0x3f);
  for(int i=1;i<=n;i++) read(x[i]),read(y[i]);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int xx=x[i],yy=y[i];
      for(int l=1;l<=n;l++)
        d[l]=abs(xx-x[l])+abs(yy-y[l]);
      sort(d+1,d+n+1);
      for(int l=1;l<=k;l++) s[l]=d[l]+s[l-1];
      for(int l=1;l<=k;l++) ans[l]=min(ans[l],s[l]);
    }
  }
  for(int i=1;i<=k;i++) cout<<ans[i]<<endl;
  return 0;
}