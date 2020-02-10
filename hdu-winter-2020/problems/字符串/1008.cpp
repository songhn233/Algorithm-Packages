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
const int maxn=1000500;
int n,m,num;
int tire[maxn][30],cnt[maxn],vis[maxn];
string s;
void insert(string s,int id)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(tire[p][s[i]-'a']) p=tire[p][s[i]-'a'];
		else
		{
			tire[p][s[i]-'a']=++num;
			p=num;
		}
		if(vis[p]!=id)cnt[p]++;
		vis[p]=id;
	}
}
int query(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(tire[p][s[i]-'a']) p=tire[p][s[i]-'a'];
		else return 0;
	}
	return cnt[p];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<s.size();j++) insert(s.substr(j),i);
	}
	cin>>m;
	while(m--)
	{
		cin>>s;
		cout<<query(s)<<endl;
	}
	return 0;
}

