#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
double x1,y1,x2,y2;
double calc(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	while(cin>>x1>>y1>>x2>>y2)
	{
		printf("%.2lf\n",calc(x1,y1,x2,y2));
	}
	return 0;
}
