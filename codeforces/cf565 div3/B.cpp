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
const int maxn=150;
ll T,n,a[maxn];
ll t[3];
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    mst(t,0);
    rep(i,1,n) rd(a[i]),a[i]%=3,t[a[i]]++;
    ll temp=min(t[1],t[2]);
    t[1]-=temp,t[2]-=temp;
    cout<<t[0]+temp+t[1]/3+t[2]/3<<endl;
  }
  return 0;
}