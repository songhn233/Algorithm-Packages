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
const int maxn=200005;
int s2[maxn][205];
int T,n,a[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        rep(i,0,n+1) rep(j,1,200) s2[i][j]=0;
        rep(i,1,n) rd(a[i]);
        for(int i=n;i>=1;i--)
        {
            rep(j,1,200) s2[i][j]=s2[i+1][j];
            s2[i][a[i]]=s2[i+1][a[i]]+1;
        }
        int ans=1;
        rep(i,1,n)
        {
            int temp=s2[1][a[i]]-s2[i+1][a[i]];
            int l=i+1,r=n;
            while(l<r)
            {
                int mid=l+r+1>>1;
                if(s2[mid][a[i]]>=temp) l=mid;
                else r=mid-1;
            }
            if(s2[i+1][a[i]]<temp) ans=max(ans,temp);
            else 
            {
                int l1=i+1,r1=l;
                int maxx=0;
                for(int k=1;k<=200;k++) maxx=max(maxx,s2[l1][k]-s2[r1][k]);
                ans=max(ans,temp*2+maxx);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}