#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define int long long
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
const int maxn=1001;
int a[maxn][maxn],t;
int n,m;
int vis[maxn][maxn],tt[maxn][maxn],d[maxn][maxn];
char c[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
    if(x<1||x>n||y<1||y>m) return false;
    if(vis[x][y]) return false;
    return true;
}
int cnt=0;
void dfs1(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int tx=dx[i]+x,ty=dy[i]+y;
        if(!calc(tx,ty)) continue;
        if(c[tx][ty]!=c[x][y]) continue;
        cnt++;
        dfs1(tx,ty);
    }
}
void dfs2(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int tx=dx[i]+x,ty=dy[i]+y;
        if(!calc(tx,ty)) continue;
        if(tt[tx][ty]==1&&cnt>=2) tt[tx][ty]=2;
        if(c[tx][ty]!=c[x][y]) continue;
        cnt++;
        dfs2(tx,ty);
    }
}
queue<PII> q;
signed main()
{
    cin>>n>>m>>t;
    int tot=0;
    for(int i=1;i<=n;i++) cin>>(c[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cnt=1;
            if(!vis[i][j]) 
            {
                dfs1(i,j);
                if(cnt==1) tt[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
    mst(d,0x3f);
    rep(i,1,n) rep(j,1,m) if(!tt[i][j]) {d[i][j]=0;vis[i][j]=1;q.push(make_pair(i,j));}
    while(!q.empty())
    {
        PII u=q.front();q.pop();
        int x=u.first,y=u.second;
        for(int i=0;i<4;i++)
        {
            int tx=dx[i]+x,ty=dy[i]+y;
            if(!calc(tx,ty)) continue;
            d[tx][ty]=d[x][y]+1;
            vis[tx][ty]=1;
            q.push(make_pair(tx,ty));
        }
    }
    while(t--)
    {
        int x,y,p;
        rd(x),rd(y),rd(p);
        if(d[x][y]>p) cout<<c[x][y]<<endl;
        else
        {
            p-=d[x][y];
            if(p&1) 
            {
                if(c[x][y]=='1') puts("0");
                else puts("1");
            }
            else cout<<c[x][y]<<endl;
        }
    }
        return 0;
}