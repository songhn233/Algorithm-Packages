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
int hh,mm,vis[1050];
PII mp[1050];
int T,n,ans,tim;
int main()
{
	cin>>T;
	while(T--)
	{
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		int x;
		char opt[5];
		int hh,mm;
		int ans,tim;
		ans=tim=0;
		while(cin>>x)
		{
			cin>>opt;
			scanf("%2d:%2d",&hh,&mm);
			if(x==0) break;
			if(opt[0]=='S')
			{
				mp[x]=make_pair(hh,mm);
				vis[x]=1;
			}
			else
			{
				if(!vis[x]) continue;
				ans++;
				vis[x]=0;
				if(mm>=mp[x].second)
				{
					int t1=mm-mp[x].second;
					int t2=(hh-mp[x].first)*60;
					tim+=(t1+t2);
				}
				else
				{
					int t1=mm-mp[x].second+60;
					int t2=(hh-mp[x].first-1)*60;
					tim+=(t1+t2);
				}
			}
		}
		if(ans) cout<<ans<<" "<<((int)((double)tim/(double)ans+0.5))<<endl;
		else puts("0 0");
	}
	return 0;
}

