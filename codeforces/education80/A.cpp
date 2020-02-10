#include<bits/stdc++.h>
using namespace std;
long long inf=9000000000;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		if(n>=d)
		{
			cout<<"YES"<<endl;
			continue;
		}
		else
		{
			int math=sqrt(d),a=inf,cnt=0;
			cout<<a<<"---"<<endl; 
			for(int i=max(1,math-11);i<=math+10;i++)
			{	cnt++;
				if(d%(i+1)!=0)  
				a=min(a,i+d/(i+1)+1);
				else a=min(a,i+d/(i+1));
			}
			
			if(a<=n)
			cout<<"YES"<<endl;
			else 
			cout<<"NO"<<endl;
		}
	}
} 
