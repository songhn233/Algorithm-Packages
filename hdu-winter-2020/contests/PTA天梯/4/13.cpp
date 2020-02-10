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
int n,m,k,top,s[1050],temp;
map<int,int> mp;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		top=0;temp=1;
		int flag=0;
		mp.clear();
		for(int j=1;j<=n;j++)
		{
			int x;read(x);
			if(x!=temp) 
			{
				s[++top]=x;
				mp[x]=1;
			}
			else 
			{
				temp++;
			}
			if(top>m)
			{
				flag=1;
			}
			if(mp[temp])
			{
				while(s[top]==temp)
				{
					top--;
					temp++;
				}
			}
		}
		if(top) flag=1;
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}

