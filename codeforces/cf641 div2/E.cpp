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
const int maxn=1001;
int a[maxn][maxn],t;
int n,m;
int vis[maxn][maxn],tt[maxn][maxn];
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
int main()
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tt[i][j]==1) continue;
            if(vis[i][j]) continue;
            cnt=1;
            dfs2(i,j);
        }
    }
    while(t--)
    {
        ll x,y,p;
        rd(x),rd(y),rd(p);
        cout<<"#"<<tt[x][y]<<endl;
        if(p==1)
        {
            if(tt[x][y]) cout<<c[x][y]<<endl;
            else
            {
                if(c[x][y]=='1') puts("0");
                else puts("1");
            }
        }
        else
        {
            if(tt[x][y]==1) cout<<c[x][y]<<endl;
            else if(tt[x][y]==2)
            {
                p--;
                if(p%2==1)
                {
                    if(c[x][y]=='1') puts("0");
                    else puts("1");
                }
                else cout<<c[x][y]<<endl;
            }
            else
            {
                if(p%2==1)
                {
                    if(c[x][y]=='1') puts("0");
                    else puts("1");
                }
                else cout<<c[x][y]<<endl;
            }
            
        }
    }
        return 0;
}