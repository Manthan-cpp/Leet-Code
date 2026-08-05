class Solution {
public:
    string originalDigits(string s) {
        vector<int> cnt(26), num(10);
        for(char c:s) cnt[c-'a']++;
        num[0]=cnt['z'-'a'];
        num[2]=cnt['w'-'a'];
        num[4]=cnt['u'-'a'];
        num[6]=cnt['x'-'a'];
        num[8]=cnt['g'-'a'];
        num[3]=cnt['h'-'a']-num[8];
        num[5]=cnt['f'-'a']-num[4];
        num[7]=cnt['s'-'a']-num[6];
        num[1]=cnt['o'-'a']-num[0]-num[2]-num[4];
        num[9]=cnt['i'-'a']-num[5]-num[6]-num[8];
        string ans;
        for(int i=0;i<10;i++)
            ans.append(num[i],char('0'+i));
        return ans;
    }
};