#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
string s,t;
int ans;
int main()
{
	cin>>s>>t;
	int n=s.size(),m=t.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int pos=0;
			for(int k=0;k<n;k++)
			{
				if(k<i||k>j)
				{
					if(s[k]==t[pos]) pos++;
				}
			}
			if(pos==m) ans=max(ans,j-i+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
