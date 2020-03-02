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
int n,pre[maxn],nex[maxn],vis[maxn];
string t,s;
int main()
{
	cin>>n;
	cin>>t;
	s=" "+t;
	for(int i=1;i<=n;i++) pre[i]=i-1,nex[i]=i+1;
	int flag=1;
	ll ans=0;
	while(flag)
	{
		char temp=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(i==1)
			{
				if(s[i]-s[nex[i]]==1) temp=max(temp,s[i]);
			}
			else if(i==n)
			{
				if(s[i]-s[pre[i]]==1) temp=max(temp,s[i]);
			}
			else
			{
				if(s[i]-s[nex[i]]==1) temp=max(temp,s[i]);
				if(s[i]-s[pre[i]]==1) temp=max(temp,s[i]);
			}
		}
		int ff=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(s[i]==temp)
			{
				if((i==1&&s[i]-s[nex[i]]==1)||(i==n&&s[i]-s[pre[i]]==1)||((i!=1&&i!=n)&&((s[i]-s[nex[i]]==1)||s[i]-s[pre[i]]==1)))
				{
					pre[nex[i]]=pre[i];
					nex[pre[i]]=nex[i];
					vis[i]=1;ff++;
				}
			}
		}
		if(!ff)
		{
			flag=0;
		}
		else ans+=ff;
	}
	cout<<ans<<endl;
	return 0;
}

