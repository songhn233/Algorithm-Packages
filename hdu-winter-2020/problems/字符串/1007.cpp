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
const int maxn=50050;
int tire[maxn][30],n,num,cnt[maxn];
string s,a[maxn];
void insert(string x)
{
	int p=0;
	for(int i=0;i<x.size();i++)
	{
		if(tire[p][x[i]-'a']) p=tire[p][x[i]-'a'];
		else
		{
			tire[p][x[i]-'a']=++num;
			p=num;
		}
	}
	cnt[p]++;
}
bool find(string x)
{
	int p=0;
	for(int i=0;i<x.size();i++)
	{
		if(!tire[p][x[i]-'a']) return false;
		p=tire[p][x[i]-'a'];
	}
	if(cnt[p]) return true;
	else return false;
}
int main()
{
	while(cin>>s)
	{
		insert(s);
		a[++n]=s;
	}
	for(int i=1;i<=n;i++)
	{
		string x=a[i];
		for(int i=0;i<x.size()-1;i++)
		{
			if(find(x.substr(0,i+1))&&find(x.substr(i+1))) 
			{
				cout<<x<<endl;
				break;
			}
		}
	}
	return 0;
}

