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
int T;
ll n,m;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        ll ans=1;
        ll i=1;
        while(i<=n)
        {
            if(i*2>n) ans=(ans*(n-i+2))%m;
            else ans=(ans*(i+1))%m;
            i*=2;
        }
        cout<<((ans-1)%m+m)%m<<endl;
    }
    return 0;
}