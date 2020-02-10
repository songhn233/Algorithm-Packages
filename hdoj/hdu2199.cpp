#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const double eps=1e-6;
int T;
double Y;
bool calc(double x)
{
	if(8*x*x*x*x+7*x*x*x+2*x*x+3*x+6<Y) return true;
	else return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>Y;
		double l=0,r=100;
		for(int i=1;i<=10000;i++)
		{
			double mid=(l+r)/2;
			if(calc(mid)) l=mid;
			else r=mid;
		}
		if(fabs(Y-8*l*l*l*l-7*l*l*l-2*l*l-3*l-6)>eps) puts("No solution!");
		else printf("%.4lf\n",l);
	}
	return 0; 
}
