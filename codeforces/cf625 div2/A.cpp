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
int n;
int a[maxn],b[maxn],sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int temp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&b[i]==1) temp++;
	}
	int t1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1&&b[i]==0) t1++;
	}
	if(t1==0)
	{
		puts("-1");
	}
	else
	{
		cout<<(temp/t1)+1<<endl;
	}
	return 0;
}

