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
const int maxn=550;
int n;
int x[maxn],y[maxn];
bool calc(int a,int b,int c)
{
	int flag=1;
	if((x[c]-x[a])*(x[c]-x[b])+(y[c]-y[a])*(y[c]-y[b])>=0) return false;
	if((x[c]-x[a])*(y[c]-y[b])-(x[c]-x[b])*(y[c]-y[a])==0) return false;
	return true;
}
int main()
{
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(calc(i,j,k)||calc(i,k,j)||calc(j,k,i)) ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

