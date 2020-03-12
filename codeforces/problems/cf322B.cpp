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
ll r,g,b;
ll p[5];
int main()
{
  cin>>r>>g>>b;
  ll t1=r/3+g/3+b/3+min(r%3,min(g%3,b%3));
  ll t2=(r-1)/3+(g-1)/3+(b-1)/3+min((r-1)%3,min((g-1)%3,(b-1)%3))+1;
  ll t3=(r-2)/3+(g-2)/3+(b-2)/3+min((r-2)%3,min((g-2)%3,(b-2)%3))+2;
  cout<<max(t1,max(t2,t3))<<endl;
  return 0;
}