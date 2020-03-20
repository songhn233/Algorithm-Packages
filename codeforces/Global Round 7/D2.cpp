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
const int maxn=2000050;
int T,n,nex[maxn];
string s;
int calc_pre(string s)
{
  string t=s;
  int n=s.size();
  reverse(s.begin(),s.end());
  t+=("#"+s);
  rep(i,0,2*n+1) nex[i]=0;
  for(int i=1,j=0;i<2*n+1;i++)
  {
    while(j&&t[j]!=t[i]) j=nex[j-1];
    if(t[i]==t[j]) j++;
    nex[i]=j;
  }
  return nex[2*n];
}
int calc_suf(string s)
{
  string t=s;
  int n=s.size();
  reverse(t.begin(),t.end());
  t+=("#"+s);
  rep(i,0,2*n+1) nex[i]=0;
  for(int i=1,j=0;i<2*n+1;i++)
  {
    while(j&&t[i]!=t[j]) j=nex[j-1];
    if(t[i]==t[j]) j++;
    nex[i]=j;
  }
  return nex[2*n];
}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>s;
    n=s.size();
    if(n==1){cout<<s<<endl;continue;}
    int i=0,j=n-1;
    int len=0,flag=0;
    while(i<j)
    {
      if(s[i]==s[j]) i++,j--,len++;
      else break;
    }
    if(len==n/2)
    {
      cout<<s<<endl;
      continue;
    }
    else
    {
      int t1=calc_pre(s.substr(i,n-2*len));
      int t2=calc_suf(s.substr(i,n-2*len));
      if(t1>t2)
      {
        string ans=s.substr(0,i+t1)+s.substr(n-1-len+1);
        cout<<ans<<endl;
      }
      else 
      {
        string ans=s.substr(0,len)+s.substr(n-1-len-t2+1);
        cout<<ans<<endl;
      }
    }
  }
  return 0;
}