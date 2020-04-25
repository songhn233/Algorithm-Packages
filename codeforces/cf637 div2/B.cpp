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
const int maxn=200050;
int T;
int n,k,a[maxn],p[maxn];
bool calc(int i)
{
    if(a[i-1]<a[i]&&a[i+1]<a[i]) return true;
    return false;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        rep(i,1,n) rd(a[i]),p[i]=0;
        rep(i,2,n-1)
        {
            if(a[i-1]<a[i]&&a[i+1]<a[i]) p[i]=1;
        }
        int ans=0,l=1;
        for(int i=1;i<=k;i++)
        {
            if(i>1&&i<k&&calc(i)) ans++;
        }
        int temp=ans;
        for(int i=2;i<=n-k+1;i++)
        {
            if(calc(i)) temp--;
            if(calc(i+k-2)) temp++;
            if(temp>ans)
            {
                ans=temp;
                l=i;
            }
        }
        cout<<ans+1<<" "<<l<<endl;
    }
    return 0;
}