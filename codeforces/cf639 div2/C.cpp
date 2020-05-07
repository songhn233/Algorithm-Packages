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
int T,n,a[maxn],b[maxn],vis[maxn];
map<int,int> mp;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        mp.clear();
        rep(i,0,n-1) 
        {
            rd(a[i]);
            b[i]=((i+a[i])%n+n)%n;
        }
        int flag=1;
        rep(i,0,n-1)
        {
            if(mp[b[i]]) {flag=0;break;}
            else mp[b[i]]=1;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}