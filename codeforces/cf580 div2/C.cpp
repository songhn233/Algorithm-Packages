#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=200050;
int n,a[maxn];
int main()
{
	cin>>n;
	if(n%2==0) puts("NO");
	else
	{
		puts("YES");
		int pan=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(pan==0)
			{
				cnt++;a[i]=cnt;
				cnt++;a[i+n]=cnt;
				pan=1;
			}
			else
			{
				cnt++;a[i+n]=cnt;
				cnt++;a[i]=cnt;
				pan=0;
			}
		}
		for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
		cout<<endl;
	}
	return 0;
}
