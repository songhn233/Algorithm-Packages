#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
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
const int maxn=200050;
int T,n,a[maxn],num,ans[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();num=0;
		for(int i=1;i<=n;i++) a[i]=read();
		int pos=0,cnt=0,pan=0;
		vector<int>pp;
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			if(ans[i]) continue;
			pp.clear();
			int t=i,temp=0;
			t=a[t];temp++;
			pp.push_back(t);
			while(t!=i)
			{
				t=a[t];
				temp++;
				pp.push_back(t);
			}
			for(int j=0;j<pp.size();j++) ans[pp[j]]=temp;
		}
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		puts(""); 
	}
	return 0;
}
