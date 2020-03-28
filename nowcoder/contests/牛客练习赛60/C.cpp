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
const int maxn=1050;
const ll p=1e9+7;
ll n,k;
ll f[maxn][maxn];
ll vis[50][maxn];
map<char,bool> mp;
string s;
int main()
{
  cin>>n>>k;
  cin>>s;
  s=" "+s;
  if(k==0)
  {
    puts("1");
    return 0;
  }
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=min(k,i);j++)
    {
      if(j==1)
      {
        if(!mp[s[i]]) 
        {
          mp[s[i]]=true;
          f[i][1]=1;
        }
        f[i][1]=(f[i][1]+f[i-1][1])%p;
      }
      else
      {
        if(!vis[s[i]-'a'][j])
        {
          f[i][j]=(f[i][j]+f[i-1][j]+f[i-1][j-1])%p;
          vis[s[i]-'a'][j]=f[i-1][j-1];
        }
        else 
        {

          f[i][j]=((f[i][j]+f[i-1][j]+f[i-1][j-1]-vis[s[i]-'a'][j])%p+p)%p;
          vis[s[i]-'a'][j]=f[i-1][j-1];
        }
      }
    }
  }
  cout<<f[n][k]<<endl;
  return 0;
}