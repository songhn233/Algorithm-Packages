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
const int maxn=105;
const ll mod=1e9+7;
ll n,m;
struct matrix{
  ll f[maxn][maxn];
  matrix operator*(const matrix t)const{
    matrix c;
    mst(c.f,0);
    for(int i=1;i<=2*n;i++)
      for(int j=1;j<=2*n;j++)
        for(int k=1;k<=2*n;k++)
          c.f[i][j]=(c.f[i][j]+f[i][k]*t.f[k][j])%mod;
    return c;
  }
};
matrix ksm(matrix a,ll b)
{
  matrix res;
  mst(res.f,0);
  for(int i=1;i<=2*n;i++) res.f[i][i]=1;
  while(b)
  {
    if(b&1) res=(res*a);
    a=a*a;
    b>>=1;
  }
  return res;
}
int main()
{
  cin>>n>>m;
  matrix s;
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(s.f[i][j]);
  if(m==1)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
        printf("%lld ",s.f[i][j]%mod);
      cout<<endl;
    }
  }
  else
  {
    matrix t;
    mst(t.f,0);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) t.f[i][j]=s.f[i][j];
    for(int i=1;i<=n;i++) t.f[i][i+n]=1;
    for(int i=n+1;i<=2*n;i++) t.f[i][i]=1;
    for(int i=n+1;i<=2*n;i++) for(int j=1;j<=n;j++) s.f[i][j]=s.f[i-n][j];
    m--;
    matrix ans=ksm(t,m);
    matrix temp=ans*s;
    for(int i=1;i<=n;i++) 
    {
      for(int j=1;j<=n;j++)
        printf("%lld ",temp.f[i][j]);
      cout<<endl;
    }
  }
  return 0;
}