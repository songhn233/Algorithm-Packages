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
const ll inf=1e16;
ll T,n,k;
ll a[35],t[100];
map<ll,ll> mp;
ll ksm(ll a,ll b)
{
  ll res=1;
  while(b)
  {
    if(b&1) res=res*a;
    a=a*a;
    b>>=1;
  }
  return res;
}
int main()
{
  cin>>T;
  while(T--)
  {
    mp.clear();
    read(n),read(k);
    ll pos=0,temp=1;
    //while(temp<inf) pos++,temp*=k;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
      read(a[i]);
      int pos=0;
      ll temp=a[i];
      while(temp)
      {
        t[pos]=temp%k;
        if(temp%k!=0&&temp%k!=1) 
        {
          flag=0;
        }
        else if(temp%k==1)
        {
          if(mp[temp%k])
          {
            flag=0;
          }
          else mp[temp%k]=1;
        }
        temp/=k;
        pos++;
      }
    }
    if(flag==0) puts("NO");
    else puts("YES");
  }
  return 0;
}