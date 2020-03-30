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
int n;
ll a[1050];
ll ans=inf,idx;
int main()
{
    cin>>n;
    rep(i,1,n) rd(a[i]);
    sort(a+1,a+n+1);
    int mid=1;
    int r=a[n];
    for(mid=1;mid<=r;mid++)
    {
        ll temp=0;
        rep(i,1,n)
        {
            temp+=min(abs(a[i]-mid),min(abs(a[i]-mid+1),abs(a[i]-mid-1)));
        }
       if(ans>temp)
       {
           ans=temp;
           idx=mid;
       }
    }
    cout<<idx<<" "<<ans<<endl;
    return 0;
}