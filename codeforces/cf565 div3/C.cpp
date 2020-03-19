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
const int maxn=500050;
int n,a[maxn],s[10];
map<ll,ll> mp;
int main()
{
  cin>>n;
  mp[4]=1,mp[8]=2,mp[15]=3,mp[16]=4,mp[23]=5,mp[42]=6;
  rep(i,1,n) 
  {
    rd(a[i]);
    if(a[i]==4) s[1]++;
    else if(s[mp[a[i]]-1]) s[mp[a[i]]-1]--,s[mp[a[i]]]++;
  }
  cout<<n-s[6]*6<<endl;
  return 0;
}