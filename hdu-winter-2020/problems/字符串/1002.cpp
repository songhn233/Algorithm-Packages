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
int tire[maxn][30],cnt[maxn],num;
string s;
void insert(string s)
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
		cnt[p]++;
	}
}
int query(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(!tire[p][s[i]-'a']) return 0;
		p=tire[p][s[i]-'a'];
	}
	return cnt[p];
}
int main()
{
	while(getline(cin,s))
	{
		if(s=="") break;
		insert(s);
	}
	while(cin>>s)
	{
		cout<<query(s)<<endl;
	}
	return 0;
}

