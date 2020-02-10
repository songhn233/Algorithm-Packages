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
int n,ans;
int c[25],p1[25],p2[25],res[10];
void dfs(int d)
{
	if(d==n+1) 
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]) continue;
		if(p1[n+i-d]||p2[i+d]) continue;
		c[i]=p1[n+i-d]=p2[i+d]=1;
		dfs(d+1);
		c[i]=p1[n+i-d]=p2[i+d]=0;
	}
	return ;
}
int main()
{
	for(int i=1;i<=10;i++)
	{
		ans=0;
		n=i;
		dfs(1);
		res[i]=ans;
	}
	while(cin>>n)
	{
		if(!n) break;
		cout<<res[n]<<endl;
	}
	return 0;
}
