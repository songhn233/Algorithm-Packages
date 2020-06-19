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
ll k;
vector<PII> p;
ll ans[10];
char c[]={'0','c','o','d','e','f','o','r','c','e','s'};
ll ksm(ll a,ll b)
{
    if(a<=0) return 0;
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a);
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    rd(k);
    if(k==1)
    {
        puts("codeforces");
        return 0;
    }
    ll t=1;
    while(ksm(t,10)<k) t++;
    ll p=10;
    while(ksm(t,p)*ksm(t-1,10-p)>=k) p--;
    p++;
    for(int i=1;i<=p;i++)
    {
        for(int j=1;j<=t;j++) printf("%c",c[i]);
    }
    for(int i=p+1;i<=10;i++)
    {
        for(int j=1;j<=t-1;j++) printf("%c",c[i]);
    }
    cout<<endl;
    return 0;
}