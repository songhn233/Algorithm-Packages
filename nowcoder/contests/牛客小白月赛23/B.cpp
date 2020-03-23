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
int T;
ll n;
vector<PII> p;
bool calc(ll mid)
{
  rep(i,0,(int)p.size()-1)
  {
    ll temp=mid,cnt=0;
    while(temp) cnt+=temp/p[i].first,temp/=p[i].first;
    if(cnt<p[i].second) return false;
  }
  return true;
}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    ll l=1,r=n;
    p.clear();
    for(ll i=2;i<=n/i;i++)
    {
      if(n%i==0)
      {
        ll t=0;
        while(n%i==0) t++,n/=i;
        p.push_back(make_pair(i,t));
      }
    }
    if(n>1) p.push_back(make_pair(n,1));
    while(l<r)
    {
      ll mid=l+r>>1;
      if(calc(mid)) r=mid;
      else l=mid+1;
    }
    cout<<l<<endl;
  }
  return 0;
}