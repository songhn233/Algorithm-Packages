#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a,b,d;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return t;
}
int main()
{
    ll x,y;
    cin>>a>>b;
    d=exgcd(a,b,x,y);
    return 0;
}