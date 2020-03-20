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
const ll p=998244353;
ll n,k;
struct node{
  ll val,id;
  bool operator<(const node&t) const{
    return val>t.val;
  }
}a[maxn],b[maxn];
bool cmp(node&x,node&y)
{
  return x.id<y.id;
} 
int main()
{
  cin>>n>>k;
  rep(i,1,n) rd(a[i].val),a[i].id=i;
  sort(a+1,a+n+1);
  ll sum=0,ans=1;
  rep(i,1,k) sum+=a[i].val;
  rep(i,1,k) b[i]=a[i];
  sort(b+1,b+k+1,cmp);
  rep(i,1,k-1) ans=(ans*(b[i+1].id-b[i].id))%p;
  cout<<sum<<" "<<ans<<endl;
  return 0;
}