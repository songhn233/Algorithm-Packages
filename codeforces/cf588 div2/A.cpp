#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int a[10];
int main()
{
	for(int i=1;i<=4;i++) cin>>a[i];
	sort(a+1,a+5);
	if(a[4]+a[1]==a[2]+a[3]) puts("YES");
	else if(a[4]==a[1]+a[2]+a[3]) puts("YES");
	else puts("NO");
	return 0;
} 
