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
const int maxn=40050;
ll n,m,k;
ll a[maxn],b[maxn];
ll ta[maxn],tb[maxn],num1=1,num2=1;
map<ll,ll> aa,bb;
vector<ll> tt;
int main()
{
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++) read(a[i]);
  for(int i=1;i<=m;i++) read(b[i]);
  for(int i=1;i<=n;i++)
  {
    if(i>1&&a[i-1]==0&&a[i]==1) ta[++num1]++;
    else if(i==1&&a[i]==0) continue;
    else if(i==1&&a[i]==1) ta[1]++;
    else if(a[i]==0) continue;
    else if(a[i]==1) ta[num1]++;
  }

  for(int i=1;i<=m;i++)
  {
    if(i>1&&b[i-1]==0&&b[i]==1) tb[++num2]++;
    else if(i==1&&b[i]==0) continue;
    else if(i==1&&b[i]==1) tb[1]++;
    else if(b[i]==0) continue;
    else if(b[i]==1) tb[num2]++;
  }
  ll ans=0;
  for(int i=1;i<=k/i;i++)
  {
    if(k%i) continue;
    else tt.push_back(i);
  }
  for(int i=1;i<=num1;i++) aa[ta[i]]++;
  for(int i=1;i<=num2;i++) bb[tb[i]]++;
  for(auto x:aa)
  {
    for(auto y:bb)
    {
      for(int t=0;t<tt.size();t++)
      {
        int p=tt[t];
        ll p1=p,p2=k/p;
        if(p1<=x.first&&p2<=y.first) ans+=x.second*y.second*(x.first-p1+1)*(y.first-p2+1);
        if(p2<=x.first&&p1<=y.first&&p1!=p2) ans+=x.second*y.second*(x.first-p2+1)*(y.first-p1+1); 
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}