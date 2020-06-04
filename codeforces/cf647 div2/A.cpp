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
ll a,b;
int T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(b%a) puts("-1");
        else
        {
            ll t=b/a;
            if(t==1) puts("0");
            else if(t%2==0)
            {
                ll ans=0;
                while(t>=8&&t%8==0) ans++,t/=8;
                while(t>=4&&t%4==0) ans++,t/=4;
                while(t>=2&&t%2==0) ans++,t/=2;
                if(t==1) cout<<ans<<endl;
                else puts("-1");
            }
            else puts("-1");
        }
        
    }
    return 0;
}