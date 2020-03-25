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
int n,a[maxn],mp[maxn],p[maxn],num;
int ch[maxn],tot,to[maxn],l,r;
int main()
{
  cin>>n;
  rep(i,1,n) 
  {
    rd(a[i]);mp[a[i]]=1;
    if(a[i]==0) 
    {
      if(l) r=i;
      else l=i;
    }
  }
  rep(i,1,n) if(!mp[i]) p[++num]=i;
  int idx=1;
  rep(i,1,n)
  {
    if(!a[i]) a[i]=p[idx],idx++;
  }
  rep(i,1,n)
  {
    if(a[i]==i)
    {
      ch[++tot]=i;
    }
  }
  if(tot==1) 
  {
    if(ch[tot]!=l) swap(a[l],a[ch[tot]]);
    else swap(a[r],a[ch[tot]]);
    rep(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
  }
  else
  {
    int temp=ch[tot];
    rep(i,1,tot-1) to[ch[i+1]]=ch[i];
    to[ch[1]]=temp;
    rep(i,1,n)
    {
      if(to[i]) cout<<to[i]<<" ";
      else cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  
  return 0;
}