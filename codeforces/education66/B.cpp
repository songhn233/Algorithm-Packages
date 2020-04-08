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
const ll inf=(1ll<<32)-1ll;
const int maxn=100050;
ll n,sta[maxn],num=1,top,s[maxn],f[maxn];
int flag=0;
int main()
{
    cin>>n;
    ll ans=0;
    rep(i,0,n) s[i]=1;
    rep(i,1,n)
    {
        string opt;ll x;
        cin>>opt;
        if(opt=="end")
        {
            if(flag) continue;
            f[top]=0;
            s[top]=1;
            top--;
        }
        if(opt=="add")
        {
            if(flag) continue;
            if(f[top]) flag=1;
            else ans+=s[top];
            if(ans>inf) flag=1;
        }
        if(opt=="for")
        {
            cin>>x;
            if(flag) continue;
            sta[++top]=x;
            s[top]=s[top-1]*x;
            if(f[top-1]) f[top]=1;
            if(s[top]>inf) f[top]=1;
        }
    }
    if(flag) puts("OVERFLOW!!!");
    else cout<<ans<<endl;
    return 0;
}