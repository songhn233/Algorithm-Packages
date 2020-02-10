#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=5000050;
const int inf=0x3f3f3f3f;
int n,k,num;
struct node{
	int val,cost;
	bool operator<(const node&t){
		return (val==t.val)?cost<t.cost:val<t.val;
	}
}a[maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i].val=read();
	num=n;
	for(int i=1;i<=n;i++)
	{
		int temp=a[i].val,p=0;
		do
		{
			temp/=2;p++;
			a[++num].val=temp;a[num].cost=p;
		}
		while(temp);
	}
	sort(a+1,a+num+1);
	int res=0,ans=inf,count=0;
	for(int i=1;i<=num;i++)
	{
		if(a[i].val!=a[i-1].val||i==1) 
		{
			res=0;count=1;
			res+=a[i].cost;
		}
		else res+=a[i].cost,count++;
		
		if(count>=k) ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
