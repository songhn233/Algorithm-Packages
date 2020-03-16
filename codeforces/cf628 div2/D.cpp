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
const int maxn=105;
ll u,v;
ll a[maxn],b[maxn],cnt[maxn],pan[maxn];
int main()
{
  cin>>u>>v;
  if(u==v&&u==0) puts("0");
  else if(u==v)
  {
    cout<<1<<endl<<u<<endl;
  }
  else if(u>v) puts("-1");
  else if((v-u)&1) puts("-1");
  else
  {
    int top=0;
    rep(i,0,62)
    {
      a[i]=u>>i&1;
      b[i]=v>>i&1;
      if(v>>i&1) top=i;
    } 
    int flag=1;
    rep(i,0,62)
    {
      if(i>top) continue;
      if(a[i]==0&&b[i]==0) 
      {
        if(i&&pan[i-1]){flag=0;break;}
        if(cnt[i-1]) cnt[i-1]=0;
        if(i==top) cnt[i]=0;
        else cnt[i]=1;
      }
      if(a[i]==0&&b[i]==1)
      {
        if(!i||(!cnt[i-1]&&!pan[i-1])){flag=0;break;}
        if(i==top) cnt[i]=0;
        else cnt[i]=1;
      }
      if(a[i]==1&&b[i]==0) 
      {
        if(!i||(!cnt[i-1]&&!pan[i-1])){flag=0;break;}
        if(i==top){flag=0;break;}
        else pan[i]=1;
      }
      if(a[i]==1&&b[i]==1)
      {
        if(i&&pan[i-1]){flag=0;break;}
        if(cnt[i-1]) cnt[i-1]=0;
        cnt[i]=0;
      }
    }
    ll x=(v-u)>>1;
    if(flag)
    {
      ll c,d;c=d=0;
      rep(i,0,62)
      {
        if(pan[i]) c+=(1ll<<i);
        if(cnt[i]) c+=(1ll<<i),d+=(1ll<<i);
        if(a[i]==1&&b[i]==1) c+=(1ll<<i);
      }
      cout<<2<<endl<<c<<" "<<d<<endl;
    }
    else cout<<3<<endl<<u<<" "<<x<<" "<<x<<endl;
  }
  return 0;
}