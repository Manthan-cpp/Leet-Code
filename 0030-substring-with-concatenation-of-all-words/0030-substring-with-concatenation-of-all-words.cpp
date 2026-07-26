class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=s.size(),m=words.size(),len=words[0].size();
        unordered_map<string,int> mp;
        for(string &w:words) mp[w]++;
        for(int offset=0;offset<len;offset++){
            unordered_map<string,int> window;
            int left=offset,count=0;
            for(int right=offset;right+len<=n;right+=len){
                string word=s.substr(right,len);
                if(mp.count(word)){
                    window[word]++;
                    count++;
                    while(window[word]>mp[word]){
                        string leftWord=s.substr(left,len);
                        window[leftWord]--;
                        left+=len;
                        count--;
                    }
                    if(count==m){
                        ans.push_back(left);
                        string leftWord=s.substr(left,len);
                        window[leftWord]--;
                        left+=len;
                        count--;
                    }
                }else{
                    window.clear();
                    count=0;
                    left=right+len;
                }
            }
        }
        return ans;
    }
};