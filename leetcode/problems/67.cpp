class Solution {
public:
    string addBinary(string a, string b) {
        int suma=0,sumb=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans="";
        int i=0,rest=0;
        while(i<a.size()||i<b.size()||rest) {
            if(i<a.size()) rest+=(a[i]-'0');
            if(i<b.size()) rest+=(b[i]-'0');
            ans+=(rest%2?'1':'0');
            rest/=2;
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};