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
const int maxn=15;
int n,m,T,vis[maxn][maxn];
char c[maxn][maxn];
PII s,t;
int flag=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool calc(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    if(c[x][y]=='X') return false;
    if(vis[x][y]) return false;
    return true;
}
void dfs(int x,int y,int tim)
{
    if(flag) return ;
    if(x==t.first&&y==t.second&&tim==T)
    {
        flag=1;
        return ;
    }
    int dis=T-tim-abs(t.first-x)-abs(t.second-y);
    if(dis<0||dis%2==1) return ;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i],ty=y+dy[i];
        if(!calc(tx,ty)) continue;
        vis[tx][ty]=1;
        dfs(tx,ty,tim+1);
        vis[tx][ty]=0;
    }
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&T))
    {
        if(!n&&!m&&!T) break;
        mst(vis,0);
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='S') {s.first=i;s.second=j;}
                if(c[i][j]=='D') {t.first=i;t.second=j;}
            }
        }
        flag=0;
        vis[s.first][s.second]=1;
        dfs(s.first,s.second,0);
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}