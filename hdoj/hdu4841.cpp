#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=100000;
int n,m;
vector<int> a;
int main()
{
	while(cin>>n>>m)
	{
		a.clear();
		for(int i=0;i<2*n;i++) a.push_back(i);
		int pos=0;
		for(int i=0;i<n;i++)
		{
			pos=(pos+m-1)%a.size();
			a.erase(a.begin()+pos);
		}
		int temp=0;
		for(int i=0;i<2*n;i++)
		{
			if((i%50==0)&&i!=0) puts("");
			if(temp<a.size()&&a[temp]==i)
			{
				cout<<'G';
				temp++;
			}
			else cout<<'B';
		}
		puts("");puts("");
	}
	return 0;
}
