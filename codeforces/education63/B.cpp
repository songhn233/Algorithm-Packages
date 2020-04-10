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
int n,m;
string s;
int vis[maxn];
char c[maxn];
int main()
{
    cin>>n>>s;
    int t=0;
    t=n-11;
    t/=2;
    int pos=0;
    rep(i,0,n-1)
    {
        if(s[i]=='8') 
        {
            pos++;
            vis[i]=1;
        }
        if(pos>=t) break;
    }
    if(pos<t) 
    {
        dep(i,n-1,0)
        {
            if(!vis[i])
            {
                vis[i]=1;
                pos++;
            }
            if(pos>=t) break;
        } 
    }
    pos=0;
    rep(i,0,n-1)
    {
        if(vis[i]) continue;
        if(s[i]=='8') continue;
        vis[i]=1;
        pos++;
        if(pos>=t) break;
    }
    rep(i,0,n-1)
    {
        if(!vis[i])
        {
            if(s[i]=='8') 
            {
                puts("YES");
                return 0;
            }
            else
            {
                puts("NO");
                return 0;
            }
        }
    }
    return 0;
}