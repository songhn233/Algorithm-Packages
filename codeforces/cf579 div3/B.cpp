#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int q,n,a[500];
int main()
{
	cin>>q;
	while(q--)
	{
		map<int,int> num;
		pair<int,int> p[500];
		cin>>n;
		for(int i=1;i<=4*n;i++) 
		{
			cin>>a[i];
			num[a[i]]++;
		}
		int flag=1;
		for(auto x:num)
		{
			if(x.second%2==1) flag=0;
		}
		if(!flag) puts("NO");
		else
		{
		    int cnt=0;
		    for(auto x:num)
		    {
			    p[++cnt].first=x.first;
			    p[cnt].second=x.second;
		    }
		    sort(p+1,p+cnt+1);
		    if(cnt==1) 
			{
				if(p[1].second<4) puts("NO");
				else puts("YES");
			}
		    else
		    {
			    int pan=1,tt;
			    tt=p[1].first*p[cnt].first;
			    if(p[1].second!=p[cnt].second) pan=0;
			    for(int i=2,j=cnt-1;i<j;i++,j--)
			    {
			    if(p[i].first*p[j].first!=tt) 
				{
				    pan=0;break;
				}
				else if(p[i].second!=p[j].second)
				{
					   pan=0;break;
				}
		    }
		    if(cnt%2==1) if(p[(cnt+1)/2].first*p[(cnt+1)/2].first!=tt) pan=0;
			if(!pan) puts("NO");
			else puts("YES");
		    }
	    }
	}
	return 0;
}
