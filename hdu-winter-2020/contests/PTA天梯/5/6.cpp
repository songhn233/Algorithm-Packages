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
const int maxn=150;
char c;
int n;
string s[maxn];
int main()
{
	cin>>c>>n;getchar();
	for(int i=1;i<=n;i++) 
	{
		s[i]=" ";
		string t;
		getline(cin,t);
		s[i]+=t;
	}
	int flag=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(s[i][j]==s[n-i+1][n-j+1]) continue;
			else flag=0;
		}
	}
	
	if(flag) puts("bu yong dao le");
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(s[i][j]!=' ') cout<<c;
			else cout<<s[i][j];
		}
			
		cout<<endl;
	}
	return 0;
}
