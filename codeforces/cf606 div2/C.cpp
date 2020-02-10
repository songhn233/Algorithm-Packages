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
const int maxn=1500050;
int T,ans[maxn],num;
string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;num=0;
		int n=s.size();
		for(int i=0;i<n-2;i++)
		{
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
			{
				if(i+4<s.size()&&(s[i+3]=='n'&&s[i+4]=='e')) ans[++num]=i+3;
				else ans[++num]=i+2;
			}
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
			{
				if(i-2>=0&&s[i-1]=='w'&&s[i-2]=='t') continue;
				ans[++num]=i+2;
			}
		}
		printf("%d\n",num);
		for(int i=1;i<=num;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

