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
int num=0;
string a[1050];
int main()
{
	string x;
	while(cin>>x)
	{
		if(x==".") break;
		a[++num]=x;
	}
	if(num<2) puts("Momo... No one is for you ...");
	else if(num<14) cout<<a[2]<<" is the only one for you..."<<endl;
	else cout<<a[2]<<" and "<<a[14]<<" are inviting you to dinner..."<<endl;
	return 0;
}
