#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int q,n;
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>n;
		int maxx=1e5,minx=-1e5,maxy=1e5,miny=-1e5;
		for(int i=1;i<=n;i++)
		{
			int x,y,t1,t2,t3,t4;
			cin>>x>>y>>t1>>t2>>t3>>t4;
			if(!t1) minx=max(minx,x);
			if(!t2) maxy=min(maxy,y);
			if(!t3) maxx=min(maxx,x);
			if(!t4) miny=max(miny,y);
		}
		if(minx>maxx||miny>maxy) puts("0");
		else cout<<1<<" "<<minx<<" "<<miny<<endl;
	}
	return 0;
}
