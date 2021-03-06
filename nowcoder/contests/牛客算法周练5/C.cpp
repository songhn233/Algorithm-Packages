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
int n,k,a[maxn];
int main()
{
    cin>>n>>k;
    int pos=0;
    rep(i,1,n) 
    {
        rd(a[i]);
        if(a[i]==1) pos=i;
    }
    int ans=inf;
    for(int l=max(1,pos-k+1);l<=pos;l++)
    {
        int r=min(n,l+k-1);
        int t1=(l+k-3)/(k-1);
        int t2=(n-r+k-2)/(k-1);
        ans=min(ans,t1+t2+1);
    }
    cout<<ans<<endl;
    return 0;
}