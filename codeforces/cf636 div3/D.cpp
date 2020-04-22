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
int N=0;
int T,n,k;
int mp[maxn],a[maxn];
int c[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        rep(i,1,n) rd(a[i]);
        rep(i,0,2*k+1) c[i]=mp[i]=0;
        rep(i,1,n/2)
        {
            int sum=a[i]+a[n-i+1];
            int t1=a[i],t2=a[n-i+1];
            if(t1>t2) swap(t1,t2);
            c[t1+1]++,c[t2+k+1]--;
            mp[sum]++;
        }
        int ans=0;
        rep(i,1,2*k) c[i]+=c[i-1];
        rep(i,2,2*k)
        {
            ans=max(ans,c[i]+mp[i]);
        }
        cout<<n-ans<<endl;
    }
    return 0;
}