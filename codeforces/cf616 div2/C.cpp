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
const int maxn=5000;
int T;
int n,m,k,a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) read(a[i]);
		if(k>=m-1)
		{
			int ans=0;
			for(int i=0;i<=m-1;i++)
			{
				int t1=a[i+1];
				int t2=a[max(1,n-(m-1-i))];
				ans=max(ans,max(t1,t2));
			}
			cout<<ans<<endl;
		}
		else
		{
			int ans=0;
			for(int i=0;i<=k;i++)
			{
				int temp=inf;
				for(int j=0;j<=m-k-1;j++)
				{
					int t1=a[min(n,i+j+1)];
					int t2=a[max(1,n-(m-1-j-i))];
					//cout<<i<<"  "<<j<<"  "<<t1<<"  "<<t2<<"---"<<endl;
					temp=min(temp,max(t1,t2));
				}
				ans=max(ans,temp);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

