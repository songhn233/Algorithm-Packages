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
const int maxn=1000;
int n,ans[maxn],num;
string s;
int main()
{
	cin>>n>>s;
	int p1,p2;
	p1=p2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='B') p1++;
		else p2++;
	}
	if((p1%2==1)&&(p2%2==1)) puts("-1");
	else 
	{
		if(p1%2==0)
		{
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='B'&&s[i+1]=='B')
				{
					s[i]='W',s[i+1]='W';
					ans[++num]=i+1;
				}
			}
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='B'&&s[i+1]=='W')
				{
					s[i]='W',s[i+1]='B';
					ans[++num]=i+1;
				}
				if(s[i]=='B'&&s[i+1]=='B')
				{
					s[i]='W',s[i+1]='W';
					ans[++num]=i+1;
				}
			}
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='B'&&s[i+1]=='B')
				{
					s[i]='W',s[i+1]='W';
					ans[++num]=i+1;
				}
			}
			cout<<num<<endl;
			for(int i=1;i<=num;i++) cout<<ans[i]<<" ";
			puts("");
		}
		else
		{
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='W'&&s[i+1]=='W')
				{
					s[i]='B',s[i+1]='B';
					ans[++num]=i+1;
				}
			}
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='W'&&s[i+1]=='B')
				{
					s[i]='B',s[i+1]='W';
					ans[++num]=i+1;
				}
				if(s[i]=='W'&&s[i+1]=='W')
				{
					s[i]='B',s[i+1]='B';
					ans[++num]=i+1;
				}
			}
			for(int i=0;i<n-1;i++)
			{
				if(s[i]=='W'&&s[i+1]=='W')
				{
					s[i]='B',s[i+1]='B';
					ans[++num]=i+1;
				}
			}
			cout<<num<<endl;
			for(int i=1;i<=num;i++) cout<<ans[i]<<" ";
			puts("");
		}
	}
	return 0;
}

