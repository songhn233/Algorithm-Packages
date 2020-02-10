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
int t1,t2;
int main()
{
	cin>>a>>b;
	int flag=0;
	for(int i=1;i<=3;i++)
	{
		int x;cin>>x;
		if(x==0) t1++;
		else t2++;
	}
	if(a<b)
	{
		swap(a,b);
		swap(t1,t2);
		flag=1;
	}
	if(t1!=0) 
	{
		if(flag) printf("The winner is b: %d + %d\n",a,t1);
		else printf("The winner is a: %d + %d\n",a,t1);
	}
	else
	{
		if(flag) printf("The winner is a: %d + %d\n",b,t2);
		else printf("The winner is b: %d + %d\n",b,t2);
	}
	return 0;
}
