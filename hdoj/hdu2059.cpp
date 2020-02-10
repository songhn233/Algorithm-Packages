#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=150;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
int n;
double l,c,t,f[maxn];
double v1,v2,v3;
double a[maxn];
int main()
{
	while(~scanf("%lf",&l))
	{
		cin>>n>>c>>t;
		cin>>v1>>v2>>v3;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<=n+1;i++) f[i]=inf;
		a[0]=0,a[n+1]=l;
		f[0]=0;
		for(int i=1;i<=n+1;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i]-a[j]<=c+eps)
				{
					if(j==0) f[i]=min(f[i],f[j]+(a[i]-a[j])/v2);
					else f[i]=min(f[i],f[j]+(a[i]-a[j])/v2+t);
				}
				
				else 
				{
					if(j==0) f[i]=min(f[i],f[j]+c/v2+(a[i]-a[j]-c)/v3);
					else f[i]=min(f[i],f[j]+c/v2+(a[i]-a[j]-c)/v3+t);
				}
			}
		}
		double temp=l/v1;
		if(temp>f[n+1]+eps) puts("What a pity rabbit!");
		else puts("Good job,rabbit!");
	}
	return 0;
}
