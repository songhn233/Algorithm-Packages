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
const double eps=1e-7;
int T,n;
string s;
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>n>>s;
    double t1=0.5,t2=0.5;
    double p1,p2;
    p1=p2=0;
    for(int i=0;i<n;i++)
    {
      p1+=t1*0.5;
      p2+=t2*0.5;
      t1*=0.5,t2*=0.5;
      if(s[i]=='M') t2+=0.5;
      else t1+=0.5;
    }
    if(fabs(p1-p2)<eps) cout<<"HM"<<endl;
    else if(p1<p2) cout<<"M"<<endl;
    else cout<<"H"<<endl;
  }
  return 0;
}