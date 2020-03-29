//hdu6579 Operation 区间线性基
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
const int maxn=500010;
int T;
int n,m,tot;
ll a[maxn],b[maxn][35],idx[maxn][35];
void add(ll x,ll num)
{
    ll tot=num;
    dep(i,30,0)
    {
        if(x>>i&1)
        {
            if(!b[num][i])
            {
                b[num][i]=x;
                idx[num][i]=tot;
                break;
            }
            else
            {
                if(idx[num][i]<tot)
                {
                    swap(x,b[num][i]);
                    swap(tot,idx[num][i]);
                }
                x^=b[num][i];
            }
        }
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        rep(i,0,n) rep(j,0,30) b[i][j]=0,idx[i][j]=0;
        ll last=0;
        rep(i,1,n) 
        {
            rd(a[i]);
            rep(j,0,30) b[i][j]=b[i-1][j],idx[i][j]=idx[i-1][j];
            add(a[i],i);
        }
        while(m--)
        {
            ll opt;rd(opt);
            if(opt==1)
            {
                ll x;rd(x);
                x^=last;
                n++;
                rep(i,0,30) b[n][i]=b[n-1][i],idx[n][i]=idx[n-1][i];
                add(x,n);
            }
            else
            {
                ll l,r;rd(l),rd(r);
                l=(l^last)%n+1;
                r=(r^last)%n+1;
                if(l>r) swap(l,r);
                ll res=0;
                dep(i,30,0)
                {
                    if(idx[r][i]>=l&&(b[r][i]^res)>res) res^=b[r][i];
                }
                last=res;
                cout<<res<<endl;
            }
        }
    }
    return 0;
}