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
const int maxn=200005;
vector<int> mp[maxn];
ll a[maxn];
ll ksm(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    int n;
    rd(n);
    ll maxx=0;
    rep(i,1,n) 
    {
        rd(a[i]);
        maxx=max(maxx,a[i]);
        int p=a[i];
        for(int j=2;j<=p/j;j++)
        {
            if(p%j==0)
            {
                int t=0;
                while(p%j==0) t++,p/=j;
                mp[j].push_back(t);
            }
        }
        if(p>1) mp[p].push_back(1);
    }
    ll ans=1;
    for(int i=1;i<=maxx;i++)
    {
        if(mp[i].size()==0) continue;
        if(mp[i].size()<=n-2) continue;
        int minx,minxx;
        minx=minxx=inf;
        for(int j=0;j<mp[i].size();j++)
        {
            int p=mp[i][j];
            if(minx>p)
            {
                minxx=minx;
                minx=p;
            }
            else if(minxx>p) minxx=p;
        }
        if(mp[i].size()==n) 
        {
            if(minxx!=inf) ans=ans*ksm(i,minxx);
            else ans=ans*ksm(i,minx);
        }
        else ans=ans*ksm(i,minx);
    }
    cout<<ans<<endl;
    return 0;
}