class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.length();
        int m=magazine.length();
        int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0;i<n;i++){
            arr1[ransomNote[i]-'a']++;
        }
        
        for(int i=0;i<m;i++){
            arr2[magazine[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(arr2[i]>=arr1[i]){
                continue;
            }
            else 
                return false;
        }
        return true;
    }
};