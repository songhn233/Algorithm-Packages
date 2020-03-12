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
const int inf=0x3f3f3f3f;
ll l,r;
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
ll calc(ll n)
{
  ll ans=0;
  if(!n) return 1;
  vector<int> nums;nums.clear();
  while(n) nums.push_back(n%10),n/=10;
  for(int i=(int)nums.size()-1;i>=0;i--)
  {
    if(i!=(int)nums.size()-1&&i>0)
    {
      ans+=9*ksm(10,i-1);
      ans+=nums[i]*ksm(10,i-1);
    }
    else if(i==(int)nums.size()-1&&i>0)
    {
      ans+=(nums[i]-1)*ksm(10,i-1);
    }
    if(i==0&&nums.back()<=nums[0]&&nums.size()>1) ans++;
    if(i==0&&nums.size()>1) ans+=10;
    else if(i==0) ans+=nums[0]+1;
  }
  return ans;
}
int main()
{
  cin>>l>>r;
  cout<<calc(r)-calc(l-1)<<endl;
  return 0;
}