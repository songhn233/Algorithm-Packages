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
const int maxn=1000005;
int t1,t2,t3;
char sta[maxn],top;
string s; 
int main()
{
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		{
			sta[++top]=s[i];
		}
		else
		{
			if(top==0)
			{
				puts("No");
				return 0;
			}
			else if(s[i]==')')
		{
			if(sta[top]!='(')
			{
				puts("No");
				return 0;
			}
			else top--;
		}
		else if(s[i]==']')
		{
			if(sta[top]!='[')
			{
				puts("No");
				return 0;
			}
			else top--;
		}
		else if(s[i]=='}')
		{
			if(sta[top]!='{')
			{
				puts("No");
				return 0;
			}
			else top--;
		}
		}
		
	}
	puts("Yes");
	return 0;
}

