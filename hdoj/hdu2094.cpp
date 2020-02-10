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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
set<string> a,b;
int n;
int main()
{
	while(cin>>n)
	{
		if(!n) break;
		a.clear(),b.clear();
		while(n--)
		{
			string t1,t2;cin>>t1>>t2;
			a.insert(t1),a.insert(t2);
			b.insert(t2);
		}
		if(a.size()-b.size()==1) puts("Yes");
		else puts("No");
	}
	return 0;
}


