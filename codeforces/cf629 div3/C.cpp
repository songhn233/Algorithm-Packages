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
const int maxn=50050;
int T,n;
int c[maxn],a[maxn],b[maxn];
string s;
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    rep(i,0,n) a[i]=b[i]=0;
    cin>>s;
    rep(i,0,n-1) c[i]=s[i]-'0';
    if(c[0]==0) a[0]=1,b[0]=2;
    else if(c[0]==1) a[0]=2,b[0]=2;
    else a[0]=1,b[0]=1;
    if(c[0]==0)
    {
      rep(i,1,n-1)
      {
        if(c[i]==0) a[i]=b[i]=0;
        if(c[i]==1) a[i]=1,b[i]=0;
        if(c[i]==2) a[i]=2,b[i]=0;
      }
    }
    else
    {
      int flag=0;
      rep(i,1,n-1)
      {
        if(flag)
        {
          if(c[i]==1) a[i]=1,b[i]=0;
          if(c[i]==2) a[i]=2,b[i]=0;
          if(c[i]==0) a[i]=b[i]=0;
        }
        else
        {
          if(c[i]==0) a[i]=b[i]=0;
          if(c[i]==2) a[i]=1,b[i]=1;
          if(c[i]==1) a[i]=0,b[i]=1,flag=1;
        }
          
      }
    }
    
    rep(i,0,n-1) cout<<a[i];
    cout<<endl;
    rep(i,0,n-1) cout<<b[i];
    cout<<endl;
  }
  return 0;
}