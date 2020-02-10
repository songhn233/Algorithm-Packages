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
	scanf("%2d:%2d",&a,&b);
	if(a>=0&&a<=11)
	{
		printf("Only %02d:%02d.  Too early to Dang.\n",a,b);
	}
	else if(a==12&&b==0)
	{
		printf("Only %02d:%02d.  Too early to Dang.\n",a,b);
	}
	else if(b==0)
	{
		a-=12;
		for(int i=1;i<=a;i++) cout<<"Dang";
		cout<<endl;
	}
	else
	{
		a-=11;
		for(int i=1;i<=a;i++) cout<<"Dang";
		cout<<endl;
	}
	return 0;
}

