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
const int maxn=150;
int T;
ll n,m;
int main()
{
  cin>>T;
  while(T--)
  {
    rd(n),rd(m);
    ll L,R;L=R=m;
    ll last=0;
    int flag=0;
    rep(i,1,n)
    {
      ll t,l,r;rd(t),rd(l),rd(r);
      L-=(t-last);
      R+=(t-last);
      if(R<l||L>r) flag=1;
      if(L<l) L=l;
      if(R>r) R=r;
      last=t;
    }
    if(flag) puts("NO");
    else puts("YES");
  }
  return 0;
}