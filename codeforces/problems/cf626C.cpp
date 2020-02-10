#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
bool calc(int mid)
{
	if(mid/2<n) return false;
	if(mid/3<m) return false;
	if(mid/2+mid/3-mid/6<n+m) return false;
	return true;
}
int main()
{
	cin>>n>>m;
	int l=0,r=3*(n+m);
	while(l<r)
	{
		int mid=l+r>>1;
		if(calc(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
