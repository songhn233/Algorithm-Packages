#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int ans=0,n;
struct node{
	int val,id;
	bool operator<(const node&t) const{
		return val>t.val;
	}
}a[1050];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) ans+=(i-1)*a[i].val+1;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) cout<<a[i].id<<" ";
	cout<<endl;
	return 0;
}
