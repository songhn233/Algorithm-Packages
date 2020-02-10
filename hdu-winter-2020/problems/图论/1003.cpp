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
int n,f[maxn][maxn],t[maxn][maxn],w[maxn];
//vector<int> path;
//void getpath(int x,int y)
//{
//	if(t[x][y]==0) return ;
//	getpath(x,t[x][y]);
//	path.push_back(t[x][y]);
//	getpath(t[x][y],y);
//}
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++) 
			{
				read(f[i][j]);
				if(f[i][j]==-1) f[i][j]=inf;
				if(i==j) f[i][j]=inf;
				t[i][j]=j;
			} 
		for(int i=1;i<=n;i++) read(w[i]);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(f[i][j]>f[i][k]+f[k][j]+w[k])
					{
						f[i][j]=f[i][k]+f[k][j]+w[k];
						t[i][j]=t[i][k];
					}
					else if(f[i][j]==f[i][k]+f[k][j]+w[k])
					{
						if(t[i][j]>t[i][k]) t[i][j]=t[i][k];
					}
				}
		int st,ed;
		while(~scanf("%d%d",&st,&ed))
		{
			if(st==-1&&ed==-1) break;
			printf("From %d to %d :\n",st,ed);
			printf("Path: ");
			cout<<st;
			int pos=st;
			while(pos!=ed)
			{
				cout<<"-->"<<t[pos][ed];
				pos=t[pos][ed];
			}
			printf("\n");
			if(st==ed) puts("Total cost : 0");
			else printf("Total cost : %d\n",f[st][ed]);
			printf("\n");
		}
	}
	return 0;
}

