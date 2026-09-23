class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = {0};

        for(char c : sentence) {
            arr[c - 'a'] = 1;
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] == 0) {
                return false;
            }
        }
        return true;
    }
};