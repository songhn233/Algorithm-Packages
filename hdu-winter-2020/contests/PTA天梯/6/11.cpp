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
map<string,int> vis,mp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		string x;cin>>x;
		vis[x]=1;
	}
	cin>>m;
	double pan=0;
	for(int i=1;i<=m;i++)
	{
		string a;int b;
		cin>>a>>b;
		mp[a]=b;
		pan+=b;
	}
	pan/=(double)m;
	int flag=0;
	for(auto x:mp)
	{
		if(x.second>pan&&!vis[x.first]) cout<<x.first<<endl,flag=1;
	}
	if(!flag) puts("Bing Mei You");
	return 0;
}
