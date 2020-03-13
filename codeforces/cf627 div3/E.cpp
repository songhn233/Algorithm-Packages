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
const int maxn=2050;
int n,h,l,r,a[maxn];
map<int,int> mp[maxn],vis[maxn];
int main()
{
  cin>>n>>h>>l>>r;
  for(int i=1;i<=n;i++) read(a[i]);
  vis[0][0]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<h;j++)
    {
      if(vis[i-1][j])
      {
        vis[i][(j+a[i])%h]=1;
        int temp=0;
        if((j+a[i])%h>=l&&(j+a[i])%h<=r) temp=1;
        else temp=0;
        mp[i][(j+a[i])%h]=max(mp[i-1][j]+temp,mp[i][(j+a[i])%h]);
        vis[i][(j+a[i]-1)%h]=1;
        if((j+a[i]-1)%h>=l&&(j+a[i]-1)%h<=r) temp=1;
        else temp=0;
        mp[i][(j+a[i]-1)%h]=max(mp[i-1][j]+temp,mp[i][(j+a[i]-1)%h]);
      }
    }
  }
  int ans=0;
  for(int i=0;i<h;i++)
  {
    ans=max(ans,mp[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}