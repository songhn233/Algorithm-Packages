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
const int maxn=100050;
const double eps=1e-7;
int n;
double x[maxn],y[maxn];
double xx,yy;
bool check(double x,double y)
{
  if(fabs(x-y)<eps) return true;
  return false;
}
int main()
{
  cin>>n;
  rep(i,1,n) cin>>x[i]>>y[i];
  if(n&1) puts("NO");
  else
  {
    int t=n>>1;
    int flag=1;
    xx=(x[1]+x[t+1])*0.5;
    yy=(y[1]+y[t+1])*0.5;
    rep(i,2,t)
    {
      if(!check((x[i]+x[t+i])*0.5,xx)||!check((y[i]+y[t+i])*0.5,yy)){flag=0;break;}
    }
    if(flag) puts("YES");
    else puts("NO");
  }
  
  return 0;
}