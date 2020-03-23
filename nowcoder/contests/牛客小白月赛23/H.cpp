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
int T,n,cnt[50],p[50];
int a[maxn];
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    mst(cnt,0);mst(p,0);
    rep(i,1,n) rd(a[i]),cnt[a[i]]++;
    int temp=2;
    for(int i=29;i>=0;i--)
    {
      if(cnt[i]>=temp)
      {
        p[i]=temp;
        temp=0;
      }
      else
      {
        p[i]=cnt[i];
        int t=temp-cnt[i];
        temp=t*2;
      }
    }
    if(temp>0) puts("impossible");
    else
    {
      string ans="";
      rep(i,1,n)
      {
        if(p[a[i]])
        {
          p[a[i]]--;
          ans+="1";
        }
        else ans+="0";
      }
      cout<<ans<<endl;
    }
    
  }
  return 0;
}