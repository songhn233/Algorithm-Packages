#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
double n,k;
int main()
{
	cin>>n>>k;
	printf("%.0lf\n",n+(3-sqrt(9+8*n+8*k))/2);
	return 0;
} 
