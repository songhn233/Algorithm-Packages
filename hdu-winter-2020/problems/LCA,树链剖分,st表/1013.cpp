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
const int maxn=200050;
int n,k,a[maxn];
int st[maxn][25];
void st_init()
{
    rep(i,1,n) st[i][0]=a[i];
    rep(j,1,20)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n<0&&k<0) break;
        int flag=0;
        rep(i,1,n) rd(a[i]);
        st_init();
        int ans=-1;
        for(int l=1;l<=n;)
        {
            if(flag) break;
            int t=n/l;
            int r=min(n/t,n);
            int temp=0;
            for(int i=1;i<=l;i++) temp+=query(1+(i-1)*t,i*t);
            if(temp>k)
            {
                ans=l;
                flag=1;
                break;
            }
            for(int i=l+1;i<=r;i++)
            {
                temp+=query(1+(i-1)*t,i*t);
                if(temp>k)
                {
                    ans=i;
                    flag=1;
                    break;
                }
            }
            l=r+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}