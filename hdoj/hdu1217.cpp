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
const int maxn=55;
map<string,int> mp;
int num,n,m,T;
double dis[maxn][maxn];
struct node{
	string u,v;
	double w;
};
int main()
{
	while(~scanf("%d",&n))
	{
	if(n==0) break;
	num=0;
	mp.clear();
	T++;
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		string x;cin>>x;
		mp[x]=++num;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string x,y;double z;
		cin>>x>>z>>y;
		dis[mp[x]][mp[y]]=z;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=max(dis[i][j],dis[i][k]*dis[k][j]);
			}
		}
	}
	int flag=0;
	for(int i=1;i<=n;i++) if(dis[i][i]>1) flag=1;
	if(flag) printf("Case %d: Yes\n",T);
	else printf("Case %d: No\n",T);
	}
	return 0;
}

