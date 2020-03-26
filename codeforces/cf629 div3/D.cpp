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
int T,n,a[maxn];
map<int,int> mp;
int main()
{
  cin>>T;
  while(T--)
  {
    mp.clear();
    cin>>n;
    rep(i,1,n) rd(a[i]),mp[a[i]]++;
    if(mp.size()==1)
    {
      cout<<1<<endl;
      rep(i,1,n) cout<<1<<" ";
      cout<<endl;
    }
    else
    {
      if(n%2==0)
      {
        cout<<2<<endl;
        rep(i,1,n) 
        {
          if(i&1) cout<<1<<" ";
          else cout<<2<<" ";
        }
        cout<<endl;
      }
      else
      {
        int flag=0;
        rep(i,2,n) if(a[i]==a[i-1]) flag=1;
        if(a[n]==a[1]) flag=1;
        if(flag)
        {
          cout<<2<<endl;
          int temp=1;
          rep(i,1,n)
          {
            if(a[i]==a[i+1]&&flag) 
            {
              cout<<temp<<" ";
              flag=0;
            }
            else
            {
              cout<<temp<<" ";
              if(temp==1) temp=2;
              else temp=1;
            }
          }
          cout<<endl;
        }
        else
        {
          cout<<3<<endl;
          rep(i,1,n-1) 
          {
            if(i&1) cout<<1<<" ";
            else cout<<2<<" ";
          }
          cout<<3<<endl;
        }
        
      }
    }
    
  }
  return 0;
}