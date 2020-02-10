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
int T,a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(a==2*b||b==2*a) puts("YES");
		else
		{
			if(a>b) swap(a,b);
			if(a==b)
			{
				if(a%3==0&&b%3==0) puts("YES");
				else puts("NO");
			}
			else
			{
				if(a<b-a) puts("NO");
				else
				{
					a=2*a-b;
					if(a%3==0) puts("YES");
					else puts("NO");
				}
			}
		}
	}
	return 0;
}
