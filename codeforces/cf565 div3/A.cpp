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
int T;
ll n;
ll t1,t2,t3;
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    t1=t2=t3=0;
    int flag=1;
    while(n%2==0) n/=2,t1++;
    while(n%3==0) n/=3,t2++; 
    while(n%5==0) n/=5,t3++;
    if(n>1) puts("-1");
    else cout<<(t1+t2*2+t3*3)<<endl;
  }
  return 0;
}