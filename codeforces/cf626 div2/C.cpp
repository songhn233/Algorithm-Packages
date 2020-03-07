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
int n,s1,s2;
string s;
int main()
{
  cin>>n>>s;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='(') s1++;
    else s2++;
  }
  if(s1!=s2) puts("-1");
  else
  {
    int t=0,last=-1;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]==')') t--;
      else t++;
      if(t<0&&last==-1)
      {
        last=i;
      }
      if(last!=-1&&t>=0)
      {
        ans+=i-last+1;
        last=-1;
      }
    }
    cout<<ans<<endl;
  }
  
  return 0;
}