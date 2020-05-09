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
const int maxn=10005;
int T;
int n,a[maxn],s[maxn];
int mp[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<=n;i++) mp[i]=0;
        s[0]=0;
        rep(i,1,n) 
        {
            rd(a[i]);
            s[i]=s[i-1]+a[i];
            if(i>1&&s[i]<=n) mp[s[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j++)
                if(s[j]-s[i]<=n) mp[s[j]-s[i]]=1;
        }
        int ans=0;
        rep(i,1,n) if(mp[a[i]]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}