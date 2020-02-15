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
const int maxn=550;
map<string,int> ma,mb;
map<int,string> mma,mmb;
int n,num1,num2;
int a[maxn][maxn],b[maxn][maxn],t1,t2,cnt[maxn],match[maxn],ch[maxn];
bool calc(int x,int y,int v)
{
	for(int i=1;i<=n;i++)
	{
		if(b[v][i]==x) return false;
		else if(b[v][i]==y) return true;
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		num1=num2=0;
		ma.clear();mb.clear();mma.clear();mmb.clear();
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
		memset(match,0,sizeof(match));memset(cnt,0,sizeof(cnt));
		t1=t2=0;
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			ma[s]=++num1;
			mma[num1]=s;
			for(int j=1;j<=n;j++)
			{
				string x;cin>>x;
				int t;
				if(mb[x]) t=mb[x],mmb[t]=x;
				else mb[x]=++num2,t=num2,mmb[t]=num2;
				a[i][j]=t;
			}
		}
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			int t=mb[s];
			for(int j=1;j<=n;j++)
			{
				string x;cin>>x;
				b[t][j]=ma[x];
			}
		}
		queue<int> q;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) q.push(i);
		for(int i=1;i<=n;i++) cnt[i]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			int v=a[u][cnt[u]];
			if(!match[v])
			{
				match[v]=u;
				ch[u]=v;
				cnt[u]++;
			}
			else
			{
				if(calc(match[v],u,v))
				{
					q.push(match[v]);
					match[v]=u;
					ch[u]=v;
				}
				else
				{
					cnt[u]++;
					q.push(u);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<mma[i]<<" "<<mmb[ch[i]]<<endl;
		}
	}
	return 0;
}

