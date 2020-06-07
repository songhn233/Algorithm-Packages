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
const int maxn=4050;
int n,m;
ll a[maxn],pos,sum,c[100];
vector<int>e[maxn];
vector<int> p;
int main()
{
    cin>>n>>m;
    rep(i,1,n) 
    {
        rd(a[i]);
        if(a[i]==-1) pos=i;
        else sum+=a[i];
    }
    ll ans=0;
    rep(i,1,m)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
        if(x!=pos&&y!=pos) ans+=a[x]^a[y];
        if(x==pos) p.push_back(y);
        if(y==pos) p.push_back(x);
    }
    ll t=0,res=0;
    for(int i=0;i<p.size();i++)
    {
        for(ll j=60;j>=0;j--)
        {
            if(a[p[i]]>>j&1) c[j]++;
        }
    }
    ll tt=p.size();
    for(ll i=60;i>=0;i--)
    {
        if(c[i]>tt/2) res+=(1ll<<i),ans+=(1ll<<i)*(tt-c[i]);
        else ans+=(1ll<<i)*c[i];
    }
    cout<<ans<<endl<<sum+res<<endl;
    return 0;
}