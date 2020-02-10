#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map> 
using namespace std;
const int maxn=250;
const int maxm=200050;
string s;
int f[maxm],n;
int tire[30][30],cnt,pan[1000];
void ins(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		int t=s[i]-'A';
		if(tire[p][t]) p=tire[p][t];
		else
		{
			tire[p][t]=++cnt;
			p=tire[p][t];
		}
	}
	pan[p]++;
}
bool query(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		int t=s[i]-'A';
		if(tire[p][t]) p=tire[p][t];
		else return false;
	}
	if(pan[p]) return true;
	else return false;
}
int main()
{
	memset(f,0,sizeof(f));
	string temp;
	while(cin>>temp)
	{
		if(temp==".") break;
		ins(temp);
		n=max(n,(int)temp.size());
	}
	s=" ";
	while(cin>>temp) s+=temp;
	int m=s.size()-1;
	f[0]=1;
	//cout<<m<<" "<<n<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=min(i,n);j++)
		{
			string temp=s.substr(i-j+1,j);
			if(query(temp)&&f[i-j])
			f[i]=1;
		}
	}
	for(int i=m;i>=0;i--)
	{
		if(f[i])
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
} 
