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
const int maxn=150;
int n,m;
int a[maxn][maxn];
int f[maxn][maxn],p[maxn][maxn];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) rd(a[i][j]);
        mst(f,0x3f);
        f[n-1][m-1]=a[n-1][m-1];
        for(int j=m-1;j>=0;j--)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(i==n-1&&j==m-1) continue;
                int pre=inf;
                if(f[i][j]>f[i][j+1]+a[i][j]) f[i][j]=f[i][j+1]+a[i][j],pre=min(pre,i);
                else if(f[i][j]==f[i][j+1]+a[i][j]) pre=min(pre,i);

                if(f[i][j]>f[(i+1)%n][j+1]+a[i][j]) f[i][j]=f[(i+1)%n][j+1]+a[i][j],pre=min(pre,(i+1)%n);
                else if(f[i][j]==f[(i+1)%n][j+1]+a[i][j]) pre=min(pre,(i+1)%n);

                if(f[i][j]>f[(i-1+n)%n][j+1]+a[i][j]) f[i][j]=f[(i-1+n)%n][j+1]+a[i][j],pre=min(pre,(i-1+n)%n);
                else if(f[i][j]==f[(i-1+n)%n][j+1]+a[i][j]) pre=min(pre,(i-1+n)%n);

                p[i][j]=pre;
            }
        }
        cout<<1<<" ";
        int pre=p[0][0];
        for(int i=1;i<=m-1;i++)
        {
            if(i!=m-1) cout<<pre+1<<" ";
            else cout<<pre+1<<endl;
            pre=p[pre][i];
        }
        cout<<f[0][0]<<endl;
    }
    return 0;
}