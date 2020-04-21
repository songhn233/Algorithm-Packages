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
int n1,n2,n3;
int T;
ll x[maxn],y[maxn],z[maxn];
ll xx[2],yy[2];
int flag[2][2];
ll ans;
ll calc(ll a,ll b,ll c)
{
    return ((a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
}
void work(ll x[],ll y[],ll z[],ll n1,ll n2,ll n3)
{
    rep(i,1,n1)
    {
        mst(flag,0);
        xx[0]=lower_bound(y+1,y+n2+1,x[i])-y;
        if(y[n2]<x[i]) xx[0]=n2;
        yy[0]=lower_bound(z+1,z+n3+1,x[i])-z;
        if(z[n3]<x[i]) yy[0]=n3;
        int l=1,r=n2;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(y[mid]<=x[i]) l=mid;
            else r=mid-1;
        }
        xx[1]=l;
        l=1,r=n3;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(z[mid]<=x[i]) l=mid;
            else r=mid-1;
        }
        yy[1]=l;
        if(y[1]>x[i]) xx[1]=1;
        if(z[1]>x[i]) yy[1]=1;
        rep(j,0,1)
        {
            rep(k,0,1)
            {
                ans=min(ans,calc(x[i],y[xx[j]],z[yy[k]]));
            }
        }
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        rd(n1),rd(n2),rd(n3);
        rep(i,1,n1) rd(x[i]);
        rep(i,1,n2) rd(y[i]);
        rep(i,1,n3) rd(z[i]);
        sort(x+1,x+n1+1);
        sort(y+1,y+n2+1);
        sort(z+1,z+n3+1);
        ans=calc(x[1],y[1],z[1]);
        work(x,y,z,n1,n2,n3);
        work(y,x,z,n2,n1,n3);
        work(z,x,y,n3,n1,n2);
        cout<<ans<<endl;
    }
    return 0;
}