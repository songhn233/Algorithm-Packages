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
const int maxn=150;
string s[maxn];
int n,m,num;
map<string,int> mp;
string ans[maxn];
int main()
{
  cin>>n>>m;
  rep(i,1,n)
  {
    string t;cin>>t;
    mp[t]++;
    s[i]=t;
  }
  int maxx=0;
  string mid;
  rep(i,1,n)
  {
    string t=s[i];
    string p=t;reverse(t.begin(),t.end());
    if(p==t&&p.size()>maxx) maxx=p.size(),mid=p;
    else if(p!=t)
    {
      if(mp[p]&&mp[t])
      {
        mp[p]--,mp[t]--;
        ans[++num]=p;
      }
    }
  }
  int res=0;
  rep(i,1,num) res+=2*((int)ans[i].size());
  res+=maxx;
  cout<<res<<endl;
  rep(i,1,num) cout<<ans[i];
  if(maxx) cout<<mid;
  dep(i,num,1)
  {
    reverse(ans[i].begin(),ans[i].end());
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}