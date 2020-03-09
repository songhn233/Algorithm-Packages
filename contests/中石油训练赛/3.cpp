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
const int maxn=505;
ll T,a[maxn];
ll n,f[maxn][maxn];
int main()
{
  cin>>T;
  for(int t=1;t<=T;t++)
  {
    read(n);
    mst(f,0);
    for(int i=1;i<=n;i++) read(a[i]),a[i+n]=a[i];
    for(int i=1;i<=2*n-2;i++) 
    {
      f[i][i+2]=a[i]*a[i+1]*a[i+2];
    }
    for(int len=4;len<=n;len++)
    {
      for(int l=1;l<=2*n-len+1;l++)
      {
        int r=l+len-1;
        for(int k=l+1;k<=r-1;k++)
        {
          f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[r]*a[k]);
        }
      }
    }
    ll ans=0;
    for(int i=1;i<=n+1;i++) ans=max(ans,f[i][i+n-1]);
    printf("Case #%d: %lld\n",t,ans);
  }
  return 0;
}