#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=200050;
int q,a[maxn],n,k,num;
int main()
{
	cin>>q;
	while(q--)
	{
	num=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]&1) num++;
	}
	if(num<k||(num-k)&1) puts("NO");
	else
	{
		puts("YES");
		int temp=0,t=1;
		while(temp<k-1)
		{ 
			if(a[t]&1)
			{
				printf("%d ",t);
				temp++;
			} 
			t++;
			//cout<<"----"<<t<<endl;
		}
		printf("%d\n",n);
	}
    }
	return 0;
}
