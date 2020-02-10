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
int n,fa[maxn];
map<int,bool> mp;
int get(int x){if(fa[x]!=x) return fa[x]=get(fa[x]); return fa[x];}
int main()
{
	cin>>n;
	string x;
	for(int i=1;i<=n+26;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=0;j<x.size();j++)
		{
			int a=get(i),b=get(x[j]-'a'+n+1);
			if(a==b) continue;
			fa[a]=b;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!mp[get(i)]) 
		{
			mp[get(i)]=true;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

