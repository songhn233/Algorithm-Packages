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
int n;
int main()
{
    double ans=inf;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double x,y,z;
        cin>>x>>y>>z;
        double temp=sqrt(x*x+y*y+z*z);
        if(temp<ans)
        {
            ans=temp;
        }
    }
    ans=((int)(ans*1000+0.5))/1000.0;
    printf("%.3lf\n",ans);
    return 0;
}