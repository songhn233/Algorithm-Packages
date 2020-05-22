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
const int maxn=1050;
int n,p[maxn],t[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
int f[maxn][maxn][2],n1,n2;
int main()
{
    cin>>n;
    int pos;
    rep(i,1,n) rd(p[i]);
    rep(i,1,n) 
    {
        rd(t[i]);
        if(t[i]==0) pos=i;
    }
    for(int i=pos-1;i>=1;i--) a[++n1]=p[pos]-p[i],c[n1]=t[i];
    for(int i=pos+1;i<=n;i++) b[++n2]=p[i]-p[pos],d[n2]=t[i];
    mst(f,0x3f);
    f[0][0][0]=f[0][0][1]=0;
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i) f[i][j][0]=min(f[i-1][j][0]+a[i]-a[i-1],f[i-1][j][1]+a[i]+b[j]);
            if(j) f[i][j][1]=min(f[i][j-1][1]+b[j]-b[j-1],f[i][j-1][0]+a[i]+b[j]);
            if(f[i][j][0]>c[i]) f[i][j][0]=inf;
            if(f[i][j][1]>d[j]) f[i][j][1]=inf;
        }
    }
    int ans=min(f[n1][n2][0],f[n1][n2][1]);
    if(ans==inf) puts("-1");
    else cout<<ans<<endl;
    return 0;
}