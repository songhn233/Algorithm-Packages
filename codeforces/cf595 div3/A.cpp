#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
const int maxn=150;
int T,n,a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=1;i<=n;i++)
		{
			if(q.empty())
			{
				q.push(a[i]);
			}
			else if(a[i]-q.top()>1)
			{
				int t=q.top();q.pop();
				q.push(a[i]);
			}
			else q.push(a[i]);
		}
		cout<<q.size()<<endl;
	}
	return 0;
}

