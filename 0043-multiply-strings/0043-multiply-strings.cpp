class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n = num1.length(), m=num2.length();
        vector<int>v (n+m+1,0);
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                v[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        reverse(v.begin(),v.end());
        for(int i=n+m;i>=1;i--){
            v[i-1]+=v[i]/10;
            v[i]=v[i]%10;
        }
        int first=0;
        while(first<=n+m && v[first]==0)
        first++;
        if(first==n+m+1)
        return "0";
        string ans="";
        for(int i = first ; i<=n+m;i++){
            ans+=to_string(v[i]);
        }
        return ans;
    }
};