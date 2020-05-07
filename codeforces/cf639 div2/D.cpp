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
const int maxn=1050;
int n,m;
char a[maxn][maxn],vis[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    if(vis[x][y]) return false;
    if(a[x][y]=='.') return false;
    return true;
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(!calc(tx,ty)) continue;
        dfs(tx,ty);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(flag) break;
        int num=0;
        for(int j=0;j<m;j++)
        {
            if(j>0&&a[i][j]=='#'&&a[i][j-1]=='.'&&num>0)
            {
                flag=1;
                break;
            }
            if(a[i][j]=='#') num++;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(flag) break;
        int num=0;
        for(int j=0;j<n;j++)
        {
            if(j>0&&a[j][i]=='#'&&a[j-1][i]=='.'&&num>0)
            {
                flag=1;
                break;
            }
            if(a[j][i]=='#') num++;
        }
    }
    int f1,f2;f1=f2=0;
    for(int i=0;i<n;i++)
    {
        int num=0;
        for(int j=0;j<m;j++) if(a[i][j]=='#') num++;
        if(!num) f1++;
    }
    for(int i=0;i<m;i++)
    {
        int num=0;
        for(int j=0;j<n;j++) if(a[j][i]=='#') num++;
        if(!num) f2++;
    }
    if((f1==0&&f2>0)||(f1>0&&f2==0)) flag=1;
    if(flag) puts("-1");
    else
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.') continue;
                if(vis[i][j]) continue;
                dfs(i,j);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}