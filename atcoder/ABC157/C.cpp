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
const int maxn=15;
int n,m,s[maxn],c[maxn],ans[maxn],vis[maxn];
int main()
{
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i]>>c[i];
		if(s[i]==1&&c[i]==0&&n>1) flag=0;
	}
	if(!flag) puts("-1");
	else
	{
		int flag=1;
		for(int i=1;i<=m;i++)
		{
			if(vis[s[i]]&&ans[s[i]]!=c[i]) 
			{
				flag=0;
				break;
			}
			vis[s[i]]=c[i];
			ans[s[i]]=c[i];
		}
		if(!flag) puts("-1");
		else 
		{
			for(int i=1;i<=n;i++) 
			{
				if(i==1&&ans[i]==0&&n>1) cout<<1;
				else cout<<ans[i];
			}
			cout<<endl;
		}
	}
	return 0;
}

