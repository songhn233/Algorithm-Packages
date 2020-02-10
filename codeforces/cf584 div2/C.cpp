#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
int T,n;
string s;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct node{
	int x,id;
	bool operator<(const node&t) const{
		if(x==t.x) return id<t.id; return x<t.x;
	}
}a[maxn];
int ans[maxn],co[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		memset(co,0,sizeof(co));
		memset(ans,0,sizeof(ans));
		cin>>n;
		cin>>s;
		for(int i=0;i<s.size();i++) a[i+1].x=s[i]-'0',a[i+1].id=i+1;
		sort(a+1,a+n+1);
		if(n==1) 
		{
		    puts("1");
		    continue;
		}
		int last=a[1].id;
		co[1]=1;
		ans[a[1].id]=1;
		int pan=0;
		for(int i=2;i<=n;)
		{
			if(pan) break;
			if(a[i].id>last)
			{
				ans[a[i].id]=1;
				co[i]=1;
				last=a[i].id;
				i++;
			}
			else
			{
				for(int j=i+1;j<=n;)
				{
					if(pan) break;
					if(a[i].x==a[j].x&&a[j].id>last) 
					{
						ans[a[j].id]=1;
						co[j]=1;
						last=a[j].id;
						j++;
					}
					else if(a[i].x==a[j].x) j++;
					else 
					{
						pan=1;
						break;
					} 
				}
				pan=1;
			}
		}
		int pp=0,s=0;
		for(int i=1;i<=n;i++) 
		{
			if(co[i]==0) 
			{
				pp=1;
				s=i;
				break;
			}
		}
		if(pp==0)
		{
			for(int i=1;i<=n;i++) printf("%d",ans[i]);
			cout<<endl;
		}
		else
		{
			int last=a[s].id;
			co[s]=2;
			ans[last]=2;
			int flag=0;
			for(int i=s+1;i<=n;i++)
			{
				if(co[i]==0)
				{
					if(last>a[i].id)
					{
						puts("-");
						flag=1;
						break;
					}
					else 
					{
						last=a[i].id;
						co[i]=2;
						ans[a[i].id]=2;
					}
				}
				
			}
			if(flag==0)
			{
				for(int i=1;i<=n;i++) printf("%d",ans[i]);
				cout<<endl;
			}
		}
		
	}
	return 0;
}
