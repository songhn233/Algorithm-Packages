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
const int maxn=100050;
int T,n,mp[maxn],k;
vector<int> g[maxn];
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n;
    rep(i,1,n) mp[i]=0,g[i].clear();
    rep(i,1,n)
    {
      rd(k);
      rep(j,1,k) 
      {
        int x;rd(x);
        g[i].push_back(x);
      }
    }
    int flag=0,t1,t2;
    rep(i,1,n)
    {
      int temp=0;
      for(int j=0;j<g[i].size();j++)
      {
        int v=g[i][j];
        if(mp[v]) continue;
        mp[v]=1,temp=1;
        break;
      }
      if(!temp)
      {
        flag=1;
        t1=i;
      }
    }
    if(flag)
    {
      puts("IMPROVE");
      cout<<t1<<" ";
      rep(i,1,n) 
      {
        if(!mp[i])
        {
          cout<<i<<endl;
          break;
        }
      }
    }
    else puts("OPTIMAL");
  }
  return 0;
}