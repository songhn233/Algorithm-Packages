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
const int maxn=50;
int n;
double a[maxn],p[maxn];
const double eps=0.01;
int main()
{
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) cin>>p[i];
    double ans=0;
    rep(i,1,n)
    {
        ans+=0.01*p[i]*a[i];
    }
    ans*=0.04;
    if(fabs(ans-4.0)<eps) puts("Yes");
    else puts("No");
    return 0;
}