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
double h,l,H,L;
int main()
{
    cin>>h>>l>>H>>L;
    if(H*l>h*L)
    {
        double ans=L*h*h;
        ans/=H;
        ans*=0.5;
        printf("%.10lf\n",ans);
    }
    else
    {
        double ans=H*l*l;
        ans/=(2*L);
        double temp=h-(H/L)*l;
        double hh=(temp*L)/sqrt(L*L+H*H);
        double dd=l*sqrt(L*L+H*H);
        dd/=L;
        ans+=dd*hh;
        printf("%.10lf\n",ans);
    }
    
    return 0;
}