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
const int maxn=1000010;
ll n,a[maxn];
ll f[maxn][5];
int main()
{
    rd(n);
    rep(i,1,n) rd(a[i]);
    mst(f,0xcf);
    f[0][0]=0;
    rep(i,1,n)
    {
        ll t=a[i]%5;
        for(int j=0;j<=4;j++) f[i][j]=f[i-1][j];
        for(int j=0;j<=4;j++)
        {
            f[i][(j+t)%5]=max(f[i][(j+t)%5],f[i-1][j]+a[i]);
        }
    }
    cout<<f[n][0]<<endl;
    return 0;
}