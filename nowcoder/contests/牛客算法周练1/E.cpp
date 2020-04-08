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
ll l,r;
queue<ll> q;
int main()
{
    cin>>l>>r;
    q.push(4);q.push(7);
    ll last=l;
    ll ans=0;
    while(!q.empty())
    {
        ll u=q.front();q.pop();
        if(u>r)
        {
            if(last==l) ans+=(r-last+1)*u;
            else ans+=(r-last)*u;
            break;
        }
        if(u>=l) 
        {
            if(last==l) ans+=(u-last+1)*u;
            else ans+=(u-last)*u;
            last=u;
        }
        q.push(u*10+4);
        q.push(u*10+7);
    }
    cout<<ans<<endl;
    return 0;
}