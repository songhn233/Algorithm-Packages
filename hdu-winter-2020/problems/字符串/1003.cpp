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
const int maxn=100050;
int tire[maxn][15],cnt[maxn],num;
int T,n;
string s,a[maxn];
void insert(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(tire[p][s[i]-'0']) p=tire[p][s[i]-'0'];
		else 
		{
			tire[p][s[i]-'0']=++num;
			p=num;
		}
		cnt[p]++;
	}
}
int query(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(!tire[p][s[i]-'0']) return 0;
		p=tire[p][s[i]-'0'];
	}
	return (cnt[p]-1);
}
int main()
{
	cin>>T;
	while(T--)
	{
		num=0;
		memset(tire,0,sizeof(tire));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>s;
			a[i]=s;
			insert(s);
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(query(a[i])) flag=1;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}

