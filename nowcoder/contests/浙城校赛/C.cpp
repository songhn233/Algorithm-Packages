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
int T;
ll x,m,n,f[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>x>>m>>n;
        f[0]=1;
        ll tot=1;
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1];
            if(i%7==1&&i!=1)
            {
                f[i]+=min(x,max(m-tot,0ll));
                tot+=x;
            }
            else if(i>=14) f[i]-=f[i-14];
        }
        if(n<8) puts("0");
        else if(n<14) cout<<f[n-8]<<endl;
        else cout<<f[n-8]-f[n-14]<<endl;
    }
    return 0;
}