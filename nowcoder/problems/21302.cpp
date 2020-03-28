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
const ll p=1e9+7;
const int maxn=55;
ll f[maxn][3],n;
string s;
int main()
{
  cin>>s;n=s.size();
  s=" "+s;
  rep(i,1,n)
  {
    f[i][(s[i]-'0')%3]=1%p;
    rep(j,0,2)
    {
      f[i][j]=(f[i][j]+f[i-1][j]+f[i-1][((j-s[i]+'0')%3+3)%3])%p;
    }
  }
  cout<<f[n][0]<<endl;
  return 0;
}