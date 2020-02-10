#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<sstream>
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
	cin>>T;getchar();
	while(T--)
	{
		int num=0;
		getline(cin,s);
		int n=s.find(','),m=s.find('.');
		if(n-3<0||m-3<=n) puts("Skipped");
		else
		{
			if(s.substr(n-3,3)=="ong"&&s.substr(m-3,3)=="ong")
		{
			stringstream sin(s);
			string t[150],x;
			while(sin>>x) t[++num]=x;
			for(int i=1;i<=num-3;i++) cout<<t[i]<<" ";
			cout<<"qiao ben zhong."<<endl;
		}
		else puts("Skipped");
		}
		
	}
	return 0;
}

