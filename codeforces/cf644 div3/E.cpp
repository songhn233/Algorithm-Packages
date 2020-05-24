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
const int maxn=55;
int T,n;
char a[maxn][maxn];
int dd[maxn][maxn],ri[maxn][maxn],p[maxn][maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>(a[i]+1);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dd[i][j]=ri[i][j]=p[i][j]=0;
        for(int i=1;i<=n;i++) dd[n+1][i]=1,ri[i][n+1]=1,p[n+1][i]=1,p[i][n+1]=1;
        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                if(dd[i+1][j]&&a[i][j]=='1') dd[i][j]=1;
                if(ri[i][j+1]&&a[i][j]=='1') ri[i][j]=1; 
            }
        }
        int flag=0;
        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                if(a[i][j]=='0') continue;
                if(ri[i][j]||dd[i][j])
                {
                    p[i][j]=1;
                    continue;
                }
                else if(p[i+1][j]||p[i][j+1]) 
                {
                    p[i][j]=1;
                    continue;
                }
                else 
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag) puts("NO");
        else puts("YES");
    }
    return 0;
}