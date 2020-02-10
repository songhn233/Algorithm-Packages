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
int T,n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a=n%10;
		int b=(n/10)%10;
		int c=(n/100)%10;
		int d=(n/1000)%10;
		int e=(n/10000)%10;
		int f=(n/100000)%10;
		if(a+b+c==d+e+f) puts("You are lucky!");
		else puts("Wish you good luck.");
	}
	return 0;
}

