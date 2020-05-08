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
const int maxn=100050;
int T,n,m,a[maxn],f[maxn],maxx[maxn],g[maxn];
int st[maxn][25];
int query(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    cin>>T;
    while(T--)
    {
        mst(f,0);mst(g,0);mst(maxx,0);
        rd(n),rd(m);
        rep(i,1,n) rd(a[i]);
        rep(i,1,n) st[i][0]=a[i];
        rep(j,1,20)
        {
            for(int i=1;i+(1<<j)-1<=n;i++)
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
        int temp=0;f[0]=0;
        for(int i=1;i<=n;i++) 
        {
            if(a[i]>temp) 
            {
                f[i]=f[i-1]+1;
                temp=a[i];
            }
            else f[i]=f[i-1];
            maxx[i]=temp;
        }
        for(int i=n;i>=1;i--)
        {
            int l=i+1,r=n;
            while(l<r)
            {
                int mid=l+r>>1;
                if(query(l,mid)>a[i]) r=mid;
                else l=mid+1;
            }
            if(a[l]>a[i]) g[i]=g[l]+1;
            else g[i]=1;
        }
        while(m--)
        {
            int p,q;rd(p),rd(q);
            int temp=f[p-1];
            if(maxx[p-1]<q) temp++;
            q=max(q,maxx[p-1]);
            int l=p+1,r=n;
            while(l<r)
            {
                int mid=l+r>>1;
                if(query(l,mid)>q) r=mid;
                else l=mid+1;
            }
            if(a[l]>q) temp+=g[l];
            cout<<temp<<endl;
        }
    }
    return 0;
}