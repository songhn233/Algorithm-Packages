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
ll T;
ll n,m,a[150],ans[150];
string s;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        rep(i,0,n-1)
        {
            cin>>s;
            a[i]=0;
            for(int j=0;j<m;j++) a[i]=a[i]*2+(s[j]-'0');
        }
        sort(a,a+n);
        ll mid=((1ll<<m)-n-1)/2;
        rep(i,0,n-1) if(a[i]<=mid) mid++;
        rep(i,0,m-1) ans[i]=mid%2,mid/=2;
        dep(i,m-1,0) cout<<ans[i];
        cout<<endl;
    }
    return 0;
}