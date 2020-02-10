#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10050;
const double eps=1e-9;
int T,n,v[maxn],m;
double P,w[maxn],f[maxn];
bool equal(double x,double y)
{
	if(fabs(x-y)<eps) return true;
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		m=0;
		cin>>P>>n;
		P=1.0-P;
		for(int i=1;i<=n;i++) cin>>v[i]>>w[i],w[i]=1.0-w[i],m+=v[i];
		memset(f,0,sizeof(f));
		f[0]=1.0;
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=v[i];j--)
				f[j]=max(f[j],f[j-v[i]]*w[i]);
		}
		for(int i=m;i>=0;i--)
		{
			if(f[i]>P||equal(f[i],P)) 
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
