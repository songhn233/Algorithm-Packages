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
const int maxn=150;
int T;
char a[maxn],b[maxn];
int p[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		memset(p,0,sizeof(p));
		cin>>(a+1)>>(b+1);
		int n=strlen(a+1),m=strlen(b+1);
		if(n>m) puts("NO");
		else
		{
			int flag=0;
			for(int i=1;i<=n;i++) p[a[i]-'a']++;
			for(int i=1;i<=m-n+1;i++)
			{
				int pan=1;
				int temp[maxn];
				memset(temp,0,sizeof(temp));
				for(int j=i;j<=i+n-1;j++) temp[b[j]-'a']++;
				for(int j=0;j<=26;j++) if(temp[j]!=p[j]) pan=0;
				if(pan) flag=1;
			}
			if(flag) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

