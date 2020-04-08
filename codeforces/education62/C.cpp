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
const int maxn=1000050;
const int N=1000000;
ll n,k;
struct node{
    ll a,b;
    bool operator<(const node&t) const{
        return b<t.b;
    }
}c[maxn];
priority_queue<ll,vector<ll>,greater<ll> > q;
int main()
{
    cin>>n>>k;
    rep(i,1,n) rd(c[i].a),rd(c[i].b);
    sort(c+1,c+n+1);
    ll ans=0,sum=0;
    for(int i=n;i>=1;i--)
    {
        sum+=c[i].a;
        if(n-i+1<=k) ans=max(ans,sum*c[i].b);
        else
        {
            while(q.size()>k-1) 
            {
                ll t=q.top();q.pop();
                sum-=t;
            }
            ans=max(ans,sum*c[i].b);
        }
        q.push(c[i].a);
    }
    cout<<ans<<endl;
    return 0;
}