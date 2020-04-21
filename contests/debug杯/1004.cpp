#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<ctime>
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
const int maxn=500050;
int T,n;
ll a[maxn];
ll sum;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        sum=0;a[0]=0;
        rep(i,1,n) 
        {
            rd(a[i]);
            if(i>1) sum+=abs(a[i]-a[i-1]);
        }
        srand(time(0));
        ll ans=sum;
        rep(i,1,min(50000,1000*n))
        {
            int t1=rand()%n+1;
            int t2=rand()%n+1;
            if(t1==t2) continue;
            if(t1>t2) swap(t1,t2);
            ll temp=0;
            if(t1>1) temp+=abs(a[t2]-a[t1-1])-abs(a[t1]-a[t1-1]);
            if(t2<n) temp+=abs(a[t2+1]-a[t1])-abs(a[t2+1]-a[t2]);
            if(sum+temp>ans) 
            {
                ans=sum+temp;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}