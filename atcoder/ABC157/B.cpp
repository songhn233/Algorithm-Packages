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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=150;
int a[maxn][maxn];
int b[maxn],n,vis[maxn][maxn],mp[maxn];
int main()
{
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) read(a[i][j]);
	cin>>n;
	for(int i=1;i<=n;i++) read(b[i]),mp[b[i]]=1;
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) if(mp[a[i][j]]) vis[i][j]=1;
	int flag=0;
	for(int i=1;i<=3;i++) if(vis[i][1]&&vis[i][2]&&vis[i][3]) flag=1;
	for(int i=1;i<=3;i++) if(vis[1][i]&&vis[2][i]&&vis[3][i]) flag=1;
	if(vis[1][1]&&vis[2][2]&&vis[3][3]) flag=1;
	if(vis[1][3]&&vis[2][2]&&vis[3][1]) flag=1;
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}

