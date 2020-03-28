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
ll x,y,a,b,c;
ll p[maxn],q[maxn],r[maxn];
int main()
{
    cin>>x>>y>>a>>b>>c;
    rep(i,1,a) rd(p[i]);
    rep(i,1,b) rd(q[i]);
    rep(i,1,c) rd(r[i]);
    sort(p+1,p+a+1);
    sort(q+1,q+b+1);
    sort(r+1,r+c+1);
    reverse(r+1,r+c+1);
    ll ans=0;
    rep(i,a-x+1,a) ans+=p[i];
    rep(i,b-y+1,b) ans+=q[i];
    ll sum=0;
    ll i=a-x+1,j=b-y+1;
    ll idx=1;
    while((i<=a||j<=b)&&idx<=c)
    {
        ll t1,t2;
        t1=t2=0;
        if(i<=a) t1=r[idx]-p[i];
        if(j<=b) t2=r[idx]-q[j];
        if(t1<=0&&t2<=0) break;
        else 
        {
            if(t1>t2) 
            {
                ans+=t1;
                i++;
                idx++;
            }
            else 
            {
                ans+=t2;
                j++;
                idx++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}