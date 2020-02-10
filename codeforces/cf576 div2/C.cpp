#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
const int maxn=400050;
int n,l,a[maxn],num,cnt,p[maxn],c[maxn],ans;
int main() 
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[++cnt]=a[i];
	}
	sort(p+1,p+n+1);
	int tot=unique(p+1,p+n+1)-(p+1);
	l=l*8;
	int tt=1;
	for(int i=2;i<tot;i<<=1) tt++;
	if(n*tt<=l) puts("0");
	else
	{
    l/=n;
	for(int i=1;i<=n;i++)
	{
	    int temp=lower_bound(p+1,p+tot+1,a[i])-p;
	    c[temp]++;
	}
	int maxx=0,lu=0;
	int temp=0;
	for(int i=1;i<=(1<<l);i++) temp+=c[i];
	//cout<<temp<<endl;
	if(maxx<temp)
	{
	        maxx=temp;
	        lu=(1<<l);
	}
	for(int i=(1<<l)+1;i<=tot;i++)
	{
	    temp+=c[i];
	    temp-=c[i-(1<<l)];
	    //cout<<temp<<endl;
	    if(maxx<temp)
	    {
	        maxx=temp;
	        lu=i;
	    }
	}
	for(int i=1;i<=(lu-(1<<l));i++) ans+=c[i];
	for(int i=lu+1;i<=tot;i++) ans+=c[i];
	cout<<ans<<endl;
	}
	//for(int i=1;i<=tot;i++) cout<<p[i]<<" "<<c[i]<<endl;
	return 0;
}
