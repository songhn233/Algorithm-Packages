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
const int maxn=3050;
const ll p=2333;
int n,m;
ll f[maxn][maxn],a[maxn][maxn];
int main()
{
    rd(n),rd(m);
    rep(i,1,n) rep(j,1,m) rd(a[i][j]);
    f[n][1]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1) continue;
            if(i-1>=1&&a[i-1][j]==0) f[i-1][j]=(f[i-1][j]+f[i][j])%p;
            if(j+1<=m&&a[i][j+1]==0) f[i][j+1]=(f[i][j+1]+f[i][j])%p;
        }
    }
    cout<<f[1][m]<<endl;
    return 0;
}