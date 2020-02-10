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
string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		int a[5],num=0;
		for(int i=0;i<n;i++)
		{
			if((s[i]-'0')%2==1) a[++num]=s[i]-'0';
			if(num==2) break;
		}
		if(num!=2) puts("-1");
		else cout<<a[1]<<a[2]<<endl;
	}
	return 0;
}

