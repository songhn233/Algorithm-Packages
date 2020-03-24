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
int n,m,k;
int main()
{
  cin>>n>>m>>k;
  rep(i,1,k) 
  {
    int a,b;rd(a),rd(b);
  }
  rep(i,1,k)
  {
    int a,b;rd(a),rd(b);
  }
  cout<<n*m+n+m-3<<endl;
  for(int i=1;i<=m-1;i++) printf("R");
  for(int i=1;i<=n-1;i++) printf("U");
  for(int i=1;i<=n;i++)
  {
    if(i&1) rep(j,1,m-1) printf("L");
    else rep(j,1,m-1) printf("R");
    if(i!=n) printf("D");
  }
  cout<<endl;
  return 0;
}