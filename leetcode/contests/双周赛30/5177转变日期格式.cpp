#include<sstream>
class Solution {
public:
    string reformatDate(string date) {
        map<string,string> mp;
        mp["Jan"]="01";
        mp["Feb"]="02";
        mp["Mar"]="03";
        mp["Apr"]="04";
        mp["May"]="05";
        mp["Jun"]="06";
        mp["Jul"]="07";
        mp["Aug"]="08";
        mp["Sep"]="09";
        mp["Oct"]="10";
        mp["Nov"]="11";
        mp["Dec"]="12";
        string a,b,c;
        stringstream sin(date);
        sin>>a>>b>>c;
        string ans=c+'-';
        a=a.substr(0,(int)a.size()-2);
        ans+=(mp[b]+'-');
        if(a.size()==1) {
            ans+='0';
            ans+=a;
        }
        else ans+=a;
        return ans;
    }
};