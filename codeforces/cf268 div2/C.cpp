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
int n;
int main()
{
  cin>>n;
  if(n<=3) puts("NO");
  else 
  {
    puts("YES");
    if(n&1)
    {
      for(int i=n;i>5;i-=2)
      {
        printf("%d - %d = 1\n",i,i-1);
        printf("1 * 1 = 1\n");
      }
      printf("5 * 4 = 20\n");
      printf("20 + 3 = 23\n");
      printf("23 + 2 = 25\n");
      printf("25 - 1 = 24\n");
    }
    else
    {
      for(int i=n;i>4;i-=2)
      {
        printf("%d - %d = 1\n",i,i-1);
        printf("1 * 1 = 1\n");
      }
      printf("1 * 2 = 2\n");
      printf("2 * 3 = 6\n");
      printf("6 * 4 = 24\n");
    }
  }
  return 0;
}