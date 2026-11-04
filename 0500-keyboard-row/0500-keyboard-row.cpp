
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (string word : words) {
            int row = 0;
            bool valid = true;

            for (char c : word) {
                c = tolower(c);

                int curr = row1.find(c) != string::npos ? 1 :
                           row2.find(c) != string::npos ? 2 : 3;

                if (row == 0) row = curr;
                else if (row != curr) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans.push_back(word);
        }

        return ans;
    }
};
