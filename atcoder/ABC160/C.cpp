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
const int maxn=400050;
ll a[maxn],k,n;
ll sum=0;
int main()
{
    cin>>k>>n;
    rep(i,1,n) rd(a[i]);
    rep(i,2,n) sum+=a[i]-a[i-1];
    ll temp=sum;
    rep(i,2,n) temp=min(temp,sum-(a[i]-a[i-1])+a[1]+k-a[n]);
    cout<<min(sum,temp)<<endl;
    return 0;
}