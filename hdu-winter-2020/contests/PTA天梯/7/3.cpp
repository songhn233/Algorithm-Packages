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
int a,b,n;
int A,B;
int main()
{
	cin>>a>>b;
	A=a,B=b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,t1,y,t2;
		cin>>x>>t1>>y>>t2;
		if(x+y==t1&&x+y!=t2) a--;
		if(x+y==t2&&x+y!=t1) b--;
		if(a==-1)
		{
			puts("A");
			cout<<B-b<<endl;
			break;
		}
		if(b==-1)
		{
			puts("B");
			cout<<A-a<<endl;
			break;
		}
	}
	return 0;
}

