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
string s,t,tt;
int n;
int main()
{
  cin>>s;
  n=s.size();
  t=s;tt=s;
  s=" "+s;
  string t1=s.substr(1,(n-1)/2);
  string t2=s.substr((n+3)/2);
  string t3=t1;reverse(t3.begin(),t3.end());
  string t4=t2;reverse(t4.begin(),t4.end());
  int f1,f2,f3;f1=f2=f3=0;
  if(t3==t1) f1=1;
  if(t2==t4) f2=1;
  reverse(tt.begin(),tt.end());
  if(tt==t) f3=1;
  if(f1&&f2&&f3) puts("Yes");
  else puts("No");
  return 0;
}