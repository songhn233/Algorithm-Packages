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
const int maxn=100050;
int n,m;
string s;
vector<int> ans;
int main()
{
	cin>>n>>m;
	cin>>s;
	int temp=0,flag=1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]=='1')
		{
			temp++;
			if(temp>=m) 
			{
				flag=0;
			}
		}
		else temp=0;
	}
	if(!flag) puts("-1");
	else
	{
		int temp=n;
		while(temp)
		{
			if(s[max(temp-m,0)]=='0') ans.push_back(min(m,temp)),temp=max(temp-m,0);
			else
			{
				int t=m;
				while(s[temp-t]!='0') t--;
				temp=temp-t;
				ans.push_back(t);
			}
		}
		for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}

