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
int n,T,a[5],num;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		num=0;
		for(int i=2;i<=n/i;i++)
		{
			if(n%i==0)
			{
				n/=i;
				a[++num]=i;
				if(num>=2) break;
			}
		}
		a[3]=n;
		if(num==2&&a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3]) 
		{
			puts("YES");
			cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		}
		else puts("NO");
	} 
	return 0;
}

