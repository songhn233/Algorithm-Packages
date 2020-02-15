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
const int maxn=1050;
int n,co[maxn],ans;
int a[maxn][maxn],flag=0;
string s;
bool calc(int x,int c)
{
	if(co[x]) return false;
	for(int i=0;i<n;i++)
	{
		if(a[i][x]&&co[i]==c) return false;
	}
	return true;
}
void dfs(int d,int c)
{
	if(flag) return ;
	if(d==n)
	{
		ans=c;
		flag=1;
		return ;
	}
	for(int i=1;i<=c;i++)
	{
		if(calc(d+1,i))
		{
			co[d+1]=i;
			dfs(d+1,c);
			co[d+1]=0;
		}
	}
	co[d]=c+1;
	dfs(d,c+1);
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0) break; 
		memset(co,0,sizeof(co));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) 
		{
			cin>>s;
			int u=s[0]-'A';
			s=s.substr(2);
			for(int j=0;j<s.size();j++)
			{
				a[u][s[j]-'A']=a[s[j]-'A'][u]=1;
			}
		}
		flag=0;
		co[0]=1;
		dfs(0,1);
		if(ans==1) puts("1 channel needed.");
		else printf("%d channels needed.\n",ans);
	}
	return 0;
}

