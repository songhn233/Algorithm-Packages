#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<ctime>
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
ll n,k,a[maxn],s[maxn][2];
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++) read(a[i]);
  for(int i=1;i<=n;i++) s[i%k][a[i]&1]++;
  ll ans=0,minx=inf,cnt=0;
  for(int i=0;i<k;i++)
  {
    if(s[i][0]>=s[i][1]) ans+=s[i][1];
    else ans+=s[i][0],cnt++;
    minx=min(minx,abs(s[i][0]-s[i][1]));
  }
  if(cnt&1) cout<<ans+minx<<endl;
  else cout<<ans<<endl;
  return 0;
}