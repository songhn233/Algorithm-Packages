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
const int maxn=55;
int n,m,k;
char c[maxn][maxn],temp[maxn][maxn];
int num,flag;
PII t[10];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    for(int i=1;i<=num;i++)
    {
        if(x==t[i].first&&y==t[i].second) return false;
    }
    if(c[x][y]=='X') return false;
    return true;
}
void dfs(int d)
{
    if(flag) return ;
    if(d==k)
    {
        for(int i=1;i<=num;i++)
        {
            if(c[t[i].first][t[i].second]=='D')
            {
                flag=1;
                break;
            }
        }
        return ;
    }
    for(int i=1;i<=num;i++)
    {
        int lastx=t[i].first,lasty=t[i].second;
        for(int j=0;j<4;j++)
        {
            int tx=t[i].first,ty=t[i].second;
            while(calc(tx+dx[j],ty+dy[j])) tx+=dx[j],ty+=dy[j];
            t[i].first=tx,t[i].second=ty;
            if(c[tx][ty]=='D') 
            {
                flag=1;
            }
            dfs(d+1);
            t[i].first=lastx,t[i].second=lasty;
        }
    }
}
int main()
{
    cin>>m>>n>>k;
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[i][j]=='R') 
            {
                num++;
                t[num].first=i;t[num].second=j;
            }
        }
    }
    dfs(0);
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}