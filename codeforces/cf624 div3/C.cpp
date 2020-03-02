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
const int maxn=200050;
int T,a[maxn];
ll n,m,s[maxn][30];
string t,p;
ll ans[30];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cin>>t;
		p=" "+t;
		for(int i=0;i<=n;i++) for(int j=0;j<26;j++) s[i][j]=0;
		for(int i=1;i<=m;i++) read(a[i]);
		for(int i=1;i<=n;i++)
		{
			s[i][p[i]-'a']++;
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<26;j++)
				s[i][j]+=s[i-1][j];	
		}
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<26;j++)
				ans[j]+=s[a[i]][j];
		}
		for(int j=0;j<26;j++) ans[j]+=s[n][j];
		for(int i=0;i<26;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}

