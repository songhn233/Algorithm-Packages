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
const int maxn=1050;
const int N=1e8;
int n,m;
int t[maxn],l[maxn],r[maxn];
int a[maxn];
int main()
{
  cin>>n>>m;
  rep(i,1,m) rd(t[i]),rd(l[i]),rd(r[i]);
  rep(i,1,m)
  {
    if(t[i]==0) continue;
    int last=a[l[i]],temp=2;
    rep(j,l[i],r[i])
    {
      if(a[i]) continue;
      else a[i]=a[i-1]+1;
    }
  }
  rep(i,1,m)
  {
    if(t[i]==1) continue;
    int flag=0;
    rep(j,l[i],r[i])
    {
      if(a[j]==0) flag=1;
      else if(j>l[i]&&a[j]<a[j-1]) flag=1;
    }
    if(!flag)
    {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  rep(i,1,n)
  {
    if(a[i]&&a[i+1]==0) a[i]=N;
  }
  rep(i,1,n)
  {
    if(a[i]==0) 
    {
      if(i==1) a[i]=N;
      else a[i]=a[i-1]-1;
    }
  }
  rep(i,1,n) 
  {
    printf("%d ",a[i]);
  }
  cout<<endl;
  return 0;
}