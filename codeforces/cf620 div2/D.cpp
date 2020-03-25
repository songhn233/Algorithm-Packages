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
const int maxn=200050;
int T,n,l[maxn],r[maxn],num;
string s;
int a[maxn],ans[maxn];
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n>>s;
    s="  "+s;
    rep(i,1,n+1) a[i]=0;
    a[1]=1;
    rep(i,2,n)
    {
      if(s[i]=='<') a[i]=1;
      else a[i]=0;  
    }
    int temp=0;rep(i,1,n) ans[i]=0;
    dep(i,n,1)
    {
      if(!a[i]) ans[i]=++temp;
    }
    num=0;rep(i,1,n) r[i]=l[i]=0;
    l[++num]=1;
    rep(i,2,n)
    {
      if(a[i]!=a[i-1]&&a[i-1]==1) r[num]=i-1;
      else if(a[i]!=a[i-1]&&a[i]==1) l[++num]=i;
    }
    if(a[n]==1) r[num]=n;
    temp=n;
    rep(i,1,num)
    {
      int t=0;
      rep(j,l[i],r[i]) ans[j]=temp-(r[i]-l[i])+t,t++;
      temp=temp-(r[i]-l[i]+1);
    }
    temp=0;
    dep(i,n,1)
    {
      if(!a[i]) ans[i]=++temp;
    }
    rep(i,1,n) printf("%d ",ans[i]);
    cout<<endl;

    temp=0;
    rep(i,1,n) ans[i]=0;
    dep(i,n,1)
    {
      if(!a[i]) ans[i]=++temp;
    }
    rep(i,1,n)
    {
      if(a[i]) ans[i]=++temp;
    }
    rep(i,1,n) printf("%d ",ans[i]);
    cout<<endl;
  }
  return 0;
}