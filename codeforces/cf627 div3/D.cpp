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
using namespace std;
template<class T>inline void read(T &x) {
  x=0; int ch=getchar(),f=0;
  while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
  while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=500050;
int T,n;
ll a[maxn],b[maxn],c[maxn],t[maxn],ha[maxn],num;
int lowbit(int x){return x&-x;}
void add(int x,int p)
{
	while(x<=num)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
int query(int x)
{
	ll res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) read(a[i]);
  for(int i=1;i<=n;i++) read(b[i]);
  for(int i=1;i<=n;i++) 
  {
  t[i]=a[i]-b[i];
  ha[++num]=t[i];
  ha[++num]=-t[i];
  }
  sort(ha+1,ha+num+1);
  num=unique(ha+1,ha+num+1)-(ha+1);
  ll ans=0;
  int temp=lower_bound(ha+1,ha+num+1,-t[n])-ha;
  add(temp,1);
  for(int i=n-1;i>=1;i--)
  {
  int temp=lower_bound(ha+1,ha+num+1,t[i])-ha;
  ans+=query(temp-1);
  int tt=lower_bound(ha+1,ha+num+1,-t[i])-ha;
  add(tt,1);
  }
  cout<<ans<<endl;
  return 0;
}