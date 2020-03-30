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
const ll p=1e9+7;
const int maxn=200050;
ll n,l,r;
ll c[3],ans;
ll f[maxn][3];
int main()
{
    cin>>n>>l>>r;
    c[l%3]=(r-l)/3+1;
    if(r>=l+1) c[(l+1)%3]=(r-l-1)/3+1;
    if(r>=l+2) c[(l+2)%3]=(r-l-2)/3+1;
    f[0][0]=1;
    rep(i,1,n)
    {
        f[i][0]=(f[i][0]+f[i-1][2]*c[1]%p+f[i-1][1]*c[2]%p+f[i-1][0]*c[0]%p)%p;
        f[i][1]=(f[i][1]+f[i-1][1]*c[0]%p+f[i-1][0]*c[1]%p+f[i-1][2]*c[2]%p)%p;
        f[i][2]=(f[i][2]+f[i-1][2]*c[0]%p+f[i-1][1]*c[1]%p+f[i-1][0]*c[2]%p)%p;
    }
    cout<<f[n][0]%p<<endl;
    return 0;
}