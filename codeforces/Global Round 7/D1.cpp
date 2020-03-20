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
const int maxn=5050;
int T,n,res,f[maxn][maxn];
string s;
map<string,bool> mp;
bool calc(string s)
{
  string t=s;
  reverse(t.begin(),t.end());
  if(s==t) return true;
  return false;
}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>s;
    if(s.size()==1) cout<<s<<endl;
    else
    {
      n=s.size();res=1;
      string ans=s.substr(0,1);
      for(int i=0;i<n;i++) 
      {
        string t=s.substr(0,i+1);
        if(calc(t)) ans=t,res=t.size();
      }
      for(int i=n-1-res;i>=0;i--)
      {
        string t=s.substr(i);
        if(calc(t)) ans=t,res=t.size();
      }
      for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
      rep(i,0,n-2) 
      {
        f[i][i]=1;
        if(s[i]==s[i+1]) f[i][i+1]=1;
      }
      for(int len=3;len<=n;len++)
      {
        for(int i=0;i<n-len+1;i++)
        {
          int j=i+len-1;
          if(s[i]==s[j])
          {
            f[i][j]=f[i+1][j-1];
          }
        }
      }
      int i=0,j=n-1;
      int temp=0;
      while(i<j)
      {
        if(s[i]==s[j]) i++,j--,temp+=2;
        else
        {
          i--;j++;
          if(i+1+n-1-j+1>res)
          {
            res=i+1+n-1-j+1;
            ans=s.substr(0,i+1)+s.substr(j);
          }
          int nex=-1;
          for(int t=i+1;t<j;t++) 
          {
            if(f[i+1][t])
            {
              nex=t;
            }
          }

          if(nex!=-1&&nex+1+n-1-j+1>res)
          {
            res=nex+1+n-1-j+1;
            ans=s.substr(0,nex+1)+s.substr(j);
          }
          nex=-1;

          for(int t=j-1;t>i;t--)
          {
            if(f[t][j-1])
            {
              nex=t;
            }
          }
          if(nex!=-1&&i+1+n-1-nex+1>res)
          {
            res=i+1+n-1-nex+1;
            ans=s.substr(0,i+1)+s.substr(nex);
          }
          break;
        }
      }
      cout<<ans<<endl;
    }
  
  }
  return 0;
}