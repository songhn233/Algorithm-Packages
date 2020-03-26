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
ll T,n,k;
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n>>k;
    ll temp=1;
    while(temp*(temp+1)/2<k) temp++;
    int idx=n-temp;
    ll rest=temp*(temp+1)/2-k+1;
    rep(i,1,idx-1) printf("a");
    printf("b");
    rep(i,idx+1,n)
    {
      if(i==idx+rest) printf("b");
      else printf("a");
    }
    cout<<endl;
  }
  return 0;
}