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
ll n,a[maxn],temp[maxn];
bool calc(int mid)
{
    int t=mid%n;
    for(int i=1;i<=n;i++) temp[i]=a[i];
    for(int i=1;i<=t;i++) temp[i]++;
    sort(temp+1,temp+n+1);
    ll sum=0,tt=temp[(n+1)/2];
    rep(i,1,n) sum+=abs(temp[i]-tt);
    if(sum<=mid) return true;
    return false;
}
int main()
{
    cin>>n;
    rep(i,1,n) rd(a[i]);
    sort(a+1,a+n+1);
    ll l=1,r=1e14;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(calc(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}