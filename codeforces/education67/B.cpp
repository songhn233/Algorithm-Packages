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
const int maxn=200050;
int n,m;
string s,t;
int mp[maxn][30],temp[30];
bool calc(int mid)
{
  int flag=1;
  rep(i,0,25)
  {
    if(temp[i]>mp[mid][i])
    {
      return false;
    }
  }
  return true;
}
int main()
{
  cin>>n>>s;
  rep(i,0,n-1)
  {
    mp[i][s[i]-'a']++;
  }
  rep(i,1,n-1)
  {
    rep(j,0,25) mp[i][j]+=mp[i-1][j];
  }
  cin>>m;
  while(m--)
  {
    cin>>t;
    mst(temp,0);
    for(int i=0;i<t.size();i++) temp[t[i]-'a']++;
    int l=0,r=n-1;
    while(l<r)
    {
      int mid=l+r>>1;
      if(calc(mid)) r=mid;
      else l=mid+1;
    }
    cout<<l+1<<endl;
  }
  return 0;
}