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
ll n,x,a[maxn];
int main()
{
    cin>>n>>x;
    rep(i,1,n) rd(a[i]),a[i+n]=a[i];
    ll sum=0,ans=0,l=1,res=0;
    for(int i=1;i<=2*n;i++)
    {
        sum+=a[i],ans+=(a[i]+1)*a[i]/2;
        if(sum<x) continue;
        while(sum>x) 
        {
            sum-=a[l];
            ans-=(a[l]+1)*a[l]/2;
            l++;
        }
        res=max(res,ans+(a[l-1]+a[l-1]-(x-sum)+1)*(x-sum)/2);
    }
    cout<<res<<endl;
    return 0;
}