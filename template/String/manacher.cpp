#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100000;
char s[N];
/* manacher template */
struct manacher{
  char s[N],str[N];
  int p[N],cnt,n;
  void init(char t[])
  {
    n=strlen(t);
    for(int i=0;i<n;i++) s[i]=t[i];
  }
  int calc()
  {
    str[0]='~',str[1]='|',cnt=2;
    for(int i=0;i<n;i++) str[cnt++]=s[i],str[cnt++]='|';
    int ans=0;
    n=n*2+2;
    for(int i=1,mid=0,r=0;i<n;i++)
    {
      if(i<=r) p[i]=min(p[max(0,mid*2-i)],r-i+1);
      while(str[i-p[i]]==str[i+p[i]]) p[i]++;
      if(i+p[i]-1>r) r=i+p[i]-1,mid=i;
      if(p[i]-1>ans) ans=p[i]-1;
    }
    return ans;
  }
};
/* example */
int main()
{
  cin>>s;
  manacher t;
  t.init(s);
  cout<<t.calc()<<endl;
  return 0;
}