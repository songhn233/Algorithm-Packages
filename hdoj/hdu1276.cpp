#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<list>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
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
		int t=2;
		list<int> a;
		list<int>::iterator it;
		for(int i=1;i<=n;i++) a.push_back(i);
		while(a.size()>3)
		{
			int pos=1;
			for(it=a.begin();it!=a.end();) 
			{
				if(pos%t==0) it=a.erase(it);
				else it++;
				pos++;
			}
			if(t==2) t=3; else t=2;
		}
		for(it=a.begin();it!=a.end();it++)
		{
			if(it!=a.begin()) printf(" ");
			printf("%d",*it);
		}
		puts("");
	}
	return 0;
}


