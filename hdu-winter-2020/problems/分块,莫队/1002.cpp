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
const int maxn=30050;
const ll p=1000000007;
ll T,n,m,a[maxn],c[maxn],cnt[maxn],num,res,inv[maxn];
ll ksm(ll a,ll b)
{
    ll res=1%p;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
struct node
{
    int l,r,id,ans;
    bool operator<(const node &t) const{
        if(c[l]==c[t.l]) return r<t.r;
        return c[l]<c[t.l];
    }
}q[maxn];
void add(ll x)
{
    cnt[a[x]]++;
    num++;
    res=(res*num)%p;
    res=(res*inv[cnt[a[x]]])%p;
}
void del(ll x)
{
    res=(res*cnt[a[x]])%p;
    res=(res*inv[num])%p;
    num--;cnt[a[x]]--;
}
bool cmp(const node&t1,const node&t2){
    return t1.id<t2.id;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        mst(cnt,0);
        res=1;num=0;
        rep(i,1,n) 
        {
            rd(a[i]);
            inv[i]=ksm(i,p-2);
        }
        int t=ceil(sqrt(n));
        rep(i,1,n) c[i]=(i-1)/t;
        rep(i,1,m) rd(q[i].l),rd(q[i].r),q[i].id=i;
        sort(q+1,q+m+1);
        ll l,r;l=r=1;
        add(1);
        for(int i=1;i<=m;i++)
        {
            while(r<q[i].r)
            {
                r++;
                add(r);
            }
            while(r>q[i].r)
            {
                del(r);
                r--;
            }
            while(l<q[i].l)
            {
                del(l);
                l++;
            }
            while(l>q[i].l)
            {
                l--;
                add(l);
            }
            q[i].ans=res;
        }
        sort(q+1,q+m+1,cmp);
        rep(i,1,m) cout<<q[i].ans<<endl;
    }
    return 0;
}