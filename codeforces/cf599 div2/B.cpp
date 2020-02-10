#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
#define PCC pair<char,char>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=1050;
int T;
int n;
string s,t;
map<PCC,int> mp;
map<PCC,int> id;
int tot=0;
char a[maxn],b[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		int flag=0;
		tot=0;
		cin>>n;
		cin>>s>>t;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i]) 
			{
				tot++;
				a[tot]=s[i],b[tot]=t[i];
			}
		}
		sort(a+1,a+tot+1);
		sort(b+1,b+tot+1);
		for(int i=1;i<=tot;i++)
		{
			if(a[i]!=b[i])
			{
				flag=1;
			}
		}
		if(flag) puts("No");
		else
		{
			puts("Yes");
		}
	}
	return 0;
}

