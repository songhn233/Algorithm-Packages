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
int T;
int n,m,a,b,ans[55][55];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>a>>b;
        if(n*a!=m*b) puts("NO");
        else
        {
            puts("YES");
            int pre=0;
            mst(ans,0);
            for(int i=1;i<=n;i++)
            {
                pre++;
                pre%=m;
                if(!pre) pre=m;
                for(int j=pre;j<=a+pre-1;j++) 
                {
                    int temp=j;
                    temp%=m;
                    if(!temp) temp=m;
                    ans[i][temp]=1;
                }
                pre=a+pre-1;
            }
            for(int i=1;i<=n;i++) 
            {
                for(int j=1;j<=m;j++) printf("%d",ans[i][j]);
                printf("\n");
            }
        }
        
    }
    return 0;
}