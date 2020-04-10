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
const int maxn=300050;
ll n,m;
ll a[maxn];
ll b[maxn];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
    cin>>n>>m;
    rep(i,1,n) rd(a[i]);
    rep(i,1,m) rd(b[i]);
    ll temp=a[2]-a[1];
    rep(i,3,n)
    {
        ll t=a[i]-a[i-1];
        temp=gcd(temp,t);
    }
    ll idx=0;
    rep(i,1,m)
    {
        if(temp%b[i]==0)
        {
            idx=i;
            break;
        }
    }
    if(idx==0) puts("NO");
    else
    {
        puts("YES");
        cout<<a[1]<<" "<<idx<<endl;
    } 
    return 0;
}