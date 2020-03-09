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
#define mp make_pair
using namespace std;
template<class T>inline void read(T &x) {
  x=0; int ch=getchar(),f=0;
  while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
  while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=1050;
int n,m,fa[maxn];
struct node{
  int x,y,z,v;
}a[maxn];
bool calc(int i,int j)
{
  ll x1=a[i].x,y1=a[i].y,z1=a[i].z;
  ll x2=a[j].x,y2=a[j].y,z2=a[j].z;
  ll temp=abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
  if(temp<=1ll) return true;
  return false;
}
int get(int x){if(x!=fa[x])fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
  x=get(x),y=get(y);
  if(x==y) return ;
  fa[x]=y;
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++) 
  {
    int x,y,z,v;
    read(x),read(y),read(z),read(v);
    a[i]={x,y,z,v};
  }
  for(int i=1;i<=n;i++) fa[i]=i;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(calc(i,j)&&abs(a[i].v-a[j].v)<=m)
      {
        merge(i,j);
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++) 
  {
    if(i==get(i)) ans++;
  }
  cout<<ans<<endl;
  return 0;
}