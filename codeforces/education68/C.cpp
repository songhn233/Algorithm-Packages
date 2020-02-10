#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
string s,t,p;
int q;
int main()
{
	cin>>q;
	while(q--)
	{
		int flag=0;
		map<char,int> mp,s1,s2;
		cin>>s>>t>>p;
		for(int i=0;i<s.size();i++) s1[s[i]]++;
		for(int i=0;i<t.size();i++) s2[t[i]]++;
		for(int i=0;i<p.size();i++) mp[p[i]]++;
		for(int i=0;i<26;i++)
		{
			char c='a'+i;
			if(s1[c]>s2[c])
			{
				flag=1;
				break;
			}
			else
			{
				if(s2[c]-s1[c]>mp[c])
				{
					flag=1;
					break;
				}
			}
		}
		int temp=0;
		for(int i=0;i<t.size();i++)
		{
			if(s[temp]==t[i]) temp++;
			if(temp==s.size()) break;
		}
		if(temp!=s.size()) flag=1;
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
