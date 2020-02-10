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
int T,n,n1,n2,t;
map<char,int> ma,mb;
map<int,char> mma,mmb;
int a[maxn][maxn],b[maxn][maxn],idx[maxn],match[maxn];
int calc(int x,int v)
{
	for(int i=1;i<=n;i++)
	{
		if(b[v][i]==x) return i;
	}
	return -1;
}
struct node{
	char a,b;
	bool operator<(const node&t) const{
		return b<t.b;
	}
}ans[maxn];
queue<int> q;
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		ma.clear();mb.clear();
		mma.clear();mmb.clear();
		memset(match,0,sizeof(match));
		while(!q.empty()) q.pop();
		n1=n2=0;
		for(int i=1;i<=n;i++) 
		{
			char c;cin>>c;
			ma[c]=++n1;
			mma[n1]=c;
		}
		for(int i=1;i<=n;i++) 
		{
			char c;cin>>c;
			mb[c]=++n2;
			mmb[n2]=c;
		}
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			char u=s[0];
			s=s.substr(2);
			for(int j=0;j<s.size();j++) a[i][j+1]=mb[s[j]];
		}
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			char u=s[0];
			s=s.substr(2);
			for(int j=0;j<s.size();j++) b[i][j+1]=ma[s[j]];
		}
		for(int i=1;i<=n;i++) q.push(i),idx[i]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			int v=a[u][idx[u]];
			if(!match[v])
			{
				match[v]=u;
				idx[u]++;
			}
			else
			{
				int temp=match[v];
				if(calc(temp,v)>calc(u,v))
				{
					match[v]=u;
					q.push(temp);
				}
				else 
				{
					q.push(u);
					idx[u]++;
				}
			}
		}
		for(int i=1;i<=n;i++) ans[i]={mmb[i],mma[match[i]]};
		sort(ans+1,ans+n+1);
		for(int i=1;i<=n;i++) cout<<ans[i].b<<" "<<ans[i].a<<endl;
		if(t!=T)puts("");
	}
	return 0;
}

