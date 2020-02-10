#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,x,y,a[100050],q[100050];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	n=read(),x=read(),y=read();
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i]=read();
	int hh=1,tt=0;
    for(int i=1;;i++)
    {
        if(hh<=tt&&i-(x+y+1)+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
        q[++tt]=i;
        
        	if(a[i-y]==a[q[hh]])
        	{
        		cout<<i-y<<endl;
        		break;
			}
    }
	return 0;
}
