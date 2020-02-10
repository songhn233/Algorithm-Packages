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
int n,m;
map<int,bool> mp;
map<int,bool> vis;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;read(k);
		for(int j=1;j<=k;j++)
		{
			int x;cin>>x;
			if(k==1) continue;
			mp[x]=true;
		}
	}
	cin>>m;
	int flag=0;
	while(m--)
	{
		int x;cin>>x;
		if(vis[x]) continue;
		if(mp[x]==false)
		{
			if(flag) 
			{
				printf(" %05d",x);
				vis[x]=true;
			}
			else 
			{
				printf("%05d",x);
				flag=1;
				vis[x]=true;
			}
		}
	}
	if(!flag) puts("No one is handsome");
	else cout<<endl;
	return 0;
}

