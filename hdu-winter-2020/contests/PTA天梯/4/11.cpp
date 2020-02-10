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
const int N=100000;
int n,num,fa[maxn],tot,flag[maxn],m;
map<string,int> mp;
struct node{
	string a,b;
}c[maxn];
int findx(int x){if(x!=fa[x]) return findx(fa[x]); return fa[x];}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		c[i]={a,b};
		mp[a]=++tot;
	}
	for(int i=1;i<=N;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(c[i].b.back()=='f'||c[i].b.back()=='m')
		{
			if(c[i].b.back()=='m') flag[mp[c[i].a]]=1;
			continue;
		}
		int len=c[i].b.size();
		if(len>4&&c[i].b.substr(len-4)=="sson")
		{
			fa[mp[c[i].a]]=mp[c[i].b.substr(0,len-4)];
			flag[mp[c[i].a]]=1;
		}
		if(len>7&&c[i].b.substr(len-7)=="sdottir")
		{
			fa[mp[c[i].a]]=mp[c[i].b.substr(0,len-7)];
		}
	}
	cin>>m;
	while(m--)
	{
		string a1,b1,a2,b2;
		cin>>a1>>b1>>a2>>b2;
		if(mp[a1]==0||mp[a2]==0) puts("NA");
		else if(flag[mp[a1]]==flag[mp[a2]]) puts("Whatever");
		else
		{
			if(findx(mp[a1])!=findx(mp[a2])) puts("Yes");
			else
			{
				int cnt=1,flag=0;
				int t1=mp[a1],t2=mp[a2];
				while(t1!=fa[t1]&&t2!=fa[t2])
				{
					t1=fa[t1];t2=fa[t2];
					cnt++;
					if(t1==t2) break;
				}
				if(cnt>=5) puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}

