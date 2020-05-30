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
const double eps=1e-8;
int T;
ll h,c,t;
double calc(ll x)
{
    return fabs(((double)((c+h)*x+c)/(double)(2*x+1))-t);
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>h>>c>>t;
        if(c==h) puts("1");
        else
        {
            double temp=(double)(h-c)/(double)(t-(h+c)*0.5);
            temp-=2.0;
            temp/=4.0;
            ll x=(ll)temp;
            double res=fabs((h+c)*0.5-t);
            int ans=2;
            for(ll i=max(0ll,x-1000);i<=x+1000;i++)
            {
                if(fabs((double)(i*(h+c)+h)/(double)(2*i+1)-t)<res)
                {
                    res=fabs((double)(i*(h+c)+h)/(double)(2*i+1)-t);
                    ans=i*2+1;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}