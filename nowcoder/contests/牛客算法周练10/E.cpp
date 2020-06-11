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
const int maxn=50050;
int L,n,m;
int a[maxn];
bool calc(int mid)
{
    int pre=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-pre<mid) cnt++;
        else pre=a[i];
    }
    return (cnt<=m);
}
int main()
{
    cin>>L>>n>>m;
    rep(i,1,n) rd(a[i]);
    int l=0,r=L;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(calc(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}