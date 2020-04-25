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
int T,n,a[maxn];
int mp[maxn],vis[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        rep(i,1,n) 
        {
            rd(a[i]);
            mp[a[i]]=i;
            vis[i]=0;
        }
        int s=1,flag=1;
        while(s<n)
        {
            int t=mp[s],last=s-1,now=s;
            for(int i=t;i<=n;i++)
            {
                if(vis[i]) break;
                vis[i]=1;
                if(a[i]!=last+1) {flag=0;break;}
                last=a[i];
                now=a[i];
            }
            if(!flag) break;
            s=now+1;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}