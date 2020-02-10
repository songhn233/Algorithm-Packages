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
int f1,f2;
string s;
int main()
{
	cin>>s;
	if(s[0]=='-')
	{
		s=s.substr(1);
		f1=1;
	}
	if((s.back()-'0')%2==0) f2=1;
	int ans=0;
	int n=s.size();
	for(int i=0;i<s.size();i++)
	{
		if((s[i]-'0')==2) ans++;
	}
	double t=(double)ans/(double)n;
	if(f1) t*=1.5;
	if(f2) t*=2;
	t*=100;
	printf("%.2lf%\n",t);
	return 0;
}

