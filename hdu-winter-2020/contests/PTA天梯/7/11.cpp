#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<sstream>
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
const int maxn=2050;
int n,m;
int h[maxn],size;
int getnum(string s)
{
	int res=0,f=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='-') f=-1;
		else res=res*10+s[i]-'0';
	}
	return res*f;
}
void up(int x)
{
	while((x>>1)&&h[x>>1]>h[x])
	{
		swap(h[x>>1],h[x]);
		x>>=1;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		h[++size]=x;
		up(size);
	}
	getchar();
	while(m--)
	{
		string s;
		getline(cin,s);
		stringstream sin(s);
		string x;
		string t[10];
		int num=0;
		while(sin>>x)
		{
			t[++num]=x;
		}
		if(t[num]=="root")
		{
			int x=getnum(t[1]);
			if(h[1]==x) puts("T");
			else puts("F");
		}
		else if(t[num]=="siblings")
		{
			int x=getnum(t[1]),y=getnum(t[3]);
			int t1,t2;t1=t2=0;
			for(int i=1;i<=size;i++) if(x==h[i]) {t1=i;break;}
			for(int i=1;i<=size;i++) if(y==h[i]) {t2=i;break;}
			if(t1==0||t2==0) puts("F");
			else
			{
				if((t1>>1)==(t2>>1)) puts("T");
				else puts("F");
			}
		}
		else if(t[num-2]=="parent")
		{
			int x=getnum(t[1]),y=getnum(t[num]);
			int t=0;
			for(int i=1;i<=size;i++) if(y==h[i]){t=i;break;}
			if(t==0) puts("F");
			else
			{
				if(h[t>>1]==x) puts("T");
				else puts("F");
			}
		}
		else
		{
			int x=getnum(t[1]),y=getnum(t[num]);
			int t=0;
			for(int i=1;i<=size;i++) if(x==h[i]){t=i;break;}
			if(t==0) puts("F");
			else
			{
				if(h[t>>1]==y) puts("T");
				else puts("F");
			}
		}
	}
	return 0;
}

