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
const int maxn=105;
int T,n,k;
int a[maxn],b[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        ll sum=0;
        rep(i,1,n) rd(a[i]),sum+=a[i];
        rep(i,1,n) rd(b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        reverse(b+1,b+n+1);
        for(int i=1;i<=k;i++) 
        {
            if(a[i]<b[i]) sum+=b[i]-a[i];
            else break;
        }
        cout<<sum<<endl;
    }
    return 0;
}