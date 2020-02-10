#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200050;
int n,m;
char a[maxn],b[maxn];
int f[maxn][maxn];
int pos1[maxn],pos2[maxn];
int main()
{
	int pan1=0,pan2=0;
    cin>>n;
    cin>>(a+1)>>(b+1);
    for(int i=1;i<=n;i++) 
    {
    	if(a[i]=='a') pan1++;
    	
    	if(b[i]=='a') pan2++;
	}
	if(pan1!=pan2) puts("-1");
	else
	{
		int t1=0,t2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='a'&&b[i]=='b') 
			{
				t1++;
				pos1[t1]=i;
			}
			
			if(a[i]=='b'&&b[i]=='a') 
			{
				t2++;
				pos2[t2]=i;
			}
		}
		if(t1%2==0&&t2%2==0)
		{
			cout<<(t1/2+t2/2)<<endl;
			for(int i=1;i<=t1;i+=2)
			{
				printf("%d %d\n",pos1[i],pos1[i+1]);
			}
			for(int i=1;i<=t2;i+=2)
			{
				printf("%d %d\n",pos2[i],pos2[i+1]);
			}
		}
		
		if(t1%2==1&&t2%2==0)
		{
			puts("-1");
		}
		else if(t1%2==0&&t2%2==1)
		{
			puts("-1");
		}
		else if(t1%2==1&&t2%2==1)
		{
			cout<<((t1/2+t2/2)+2)<<endl;
			for(int i=1;i<=t1-1;i+=2)
			{
				printf("%d %d\n",pos1[i],pos1[i+1]);
			}
			for(int i=1;i<=t2-1;i+=2)
			{
				printf("%d %d\n",pos2[i],pos2[i+1]);
			}
			printf("%d %d\n",pos1[t1],pos1[t1]);
			printf("%d %d\n",pos2[t2],pos1[t1]);
		}
	}
    return 0;
}
