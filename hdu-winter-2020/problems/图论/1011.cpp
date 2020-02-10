#include<cstdio>
#include<algorithm>
#include<cstring>
#include<sstream>
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
int n,cnt,m,tot,t;
map<string,int> mp;
int f[maxn][maxn];
int res[maxn];
int getnum(string s)
{
	int res=0;
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') flag=1;
		if(flag&&!(s[i]>='0'&&s[i]<='9')) break;
		if(!(s[i]>='0'&&s[i]<='9')) continue;
		int temp=s[i]-'0';
		res=res*10+temp;
	}
	return res;
}
int main()
{
	while(~scanf("%d%d%d",&n,&cnt,&m))
	{
		t++;
		if(n==0&&cnt==0&&m==0) break;
		mp.clear();
		memset(f,0x3f,sizeof(f));
		memset(res,0,sizeof(res));
		for(int i=1;i<=n;i++) f[i][i]=0;
		tot=0;
		for(int i=1;i<=cnt+1;i++) 
		{
			string s;cin>>s;
			if(mp[s]) res[i]=mp[s];
			else mp[s]=++tot,res[i]=mp[s];
		}
		for(int i=1;i<=m;i++)
		{
			string t1,t2,t3;
			cin>>t1>>t2>>t3;
			int u,v,w;
			if(mp[t1]) u=mp[t1]; 
			else mp[t1]=++tot,u=tot;
			if(mp[t3]) v=mp[t3]; 
			else mp[t3]=++tot,v=tot;
			w=getnum(t2);
			if(t2[0]=='<') 
			{
				if(w<f[v][u]) f[v][u]=w;
			}
			if(t2[t2.size()-1]=='>') 
			{
				if(w<f[u][v]) f[u][v]=w;
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		int ans=0;
		for(int i=2;i<=cnt+1;i++) ans+=f[res[1]][res[i]]+f[res[i]][res[1]];
		printf("%d. %d\n",t,ans);
	}
	return 0;
}

