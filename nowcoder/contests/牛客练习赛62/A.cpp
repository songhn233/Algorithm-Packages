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
int T,n,m;
int a[maxn][maxn];
bool calc(int x,int y,int z)
{
    int res=0;
    if(a[x][y]) res++;
    if(a[x][z]) res++;
    if(a[y][z]) res++;
    if(res==3||res==0) return true;
    return false;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        mst(a,0);
        rep(i,1,m)
        {
            int x,y;rd(x),rd(y);
            if(n<6) a[x][y]=a[y][x]=1;
        }
        if(n>=6) puts("yes");
        else if(n<3) puts("no");
        else
        {
            int flag=0;
            for(int i=1;i<=n;i++)
            {
                if(flag) break;
                for(int j=i+1;j<=n;j++)
                {
                    if(flag) break;
                    for(int k=j+1;k<=n;k++)
                    {
                        if(calc(i,j,k))
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(flag) puts("yes");
            else puts("no");
        }
        
    }
    return 0;
}