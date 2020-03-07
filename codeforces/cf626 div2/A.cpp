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
const int maxn=150;
int T,n;
int a[maxn];
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    int flag=0,temp=0;
    for(int i=1;i<=n;i++)
    {
      read(a[i]);
      if(a[i]%2==0) flag=1;
      else temp++;
    }
    if(flag)
    {
      puts("1");
      for(int i=1;i<=n;i++)
      {
        if(a[i]%2==0)
        {
          cout<<i<<endl;
          break;
        }
      }
    }
    else if(temp>=2)
    {
      int t=0;
      for(int i=1;i<=n;i++)
      {
        if(a[i]%2)
        {
          cout<<i<<" ";
          t++;
        }
        if(t>=2) break;
      }
      cout<<endl;
    }
    else puts("-1");
  }
  return 0;
}