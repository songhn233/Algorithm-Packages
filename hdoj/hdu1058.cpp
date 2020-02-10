#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=6000;
const int N=5842;
int n,f[maxn];
int main()
{
	int a,b,c,d;
	a=b=c=d=1;
	f[1]=1;
	for(int i=2;i<=N;i++)
	{
		int p=min(f[a]*2,min(f[b]*3,min(f[c]*5,f[d]*7)));
		if(p==f[a]*2) f[i]=f[a]*2,a++;
		if(p==f[b]*3) f[i]=f[b]*3,b++;
		if(p==f[c]*5) f[i]=f[c]*5,c++;
		if(p==f[d]*7) f[i]=f[d]*7,d++;
	}
	while(cin>>n)
	{
		if(n==0) break;
		
		if(n%10==1&&n%100!=11)
			printf("The %dst humble number is %d.\n",n,f[n]);
		else if(n%10==2&&n%100!=12)
        	printf("The %dnd humble number is %d.\n",n,f[n]);
        else if(n%10==3&&n%100!=13)
        	printf("The %drd humble number is %d.\n",n,f[n]);
        else
        	printf("The %dth humble number is %d.\n",n,f[n]);
	}
	return 0;
}
