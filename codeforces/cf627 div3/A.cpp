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
int T,n;
int a[150];
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    int f1,f2;
    f1=f2=0;
    for(int i=1;i<=n;i++)
    {
      read(a[i]);
      if(a[i]%2) f1=1;
      else f2=1;
    }
    if(f1&&f2==0||f2&&f1==0) puts("YES");
    else puts("NO");
  }
  return 0;
}