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
int T;
string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		int l,r,u,d;
		l=r=u=d=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='D') d++;
			if(s[i]=='U') u++;
			if(s[i]=='L') l++;
			if(s[i]=='R') r++;
		}
		int t1=min(l,r),t2=min(d,u);
		if(t1==0&&t2==0)
		{
			puts("0");
			puts("");
		}
		else if(t1==0)
		{
			puts("2");
			puts("DU");
		}
		else if(t2==0)
		{
			puts("2");
			puts("LR");
		}
		else
		{
			cout<<t1*2+t2*2<<endl;
			for(int i=1;i<=t1;i++) cout<<"L";
			for(int i=1;i<=t2;i++) cout<<"D";
			for(int i=1;i<=t1;i++) cout<<"R";
			for(int i=1;i<=t2;i++) cout<<"U";
			puts("");
		}
	}
	return 0;
}

