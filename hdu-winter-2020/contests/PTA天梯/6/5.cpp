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
int a,b;
int main()
{
	cin>>a>>b;
	if(b>0)
	{
		double ans=(double)a/(double)b;
		printf("%d/%d=%.2lf\n",a,b,ans);
	}
	else if(b==0)
	{
		printf("%d/%d=Error",a,b);
	}
	else
	{
		double ans=(double)a/(double)b;
		printf("%d/(%d)=%.2lf\n",a,b,ans);
	}
	return 0;
}
