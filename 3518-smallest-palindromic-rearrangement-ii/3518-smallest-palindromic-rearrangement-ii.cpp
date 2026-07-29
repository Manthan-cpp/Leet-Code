class Solution {
public:
    static constexpr int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        vector<int> half(26);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] & 1)
                mid = char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        string left;
        int len = accumulate(half.begin(), half.end(), 0);

        while (left.size() < len) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;

                int ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;
        return left + right;
    }

private:
    int countWays(vector<int>& cnt) {
        int total = accumulate(cnt.begin(), cnt.end(), 0);
        long long res = 1;

        for (int x : cnt) {
            if (x == 0)
                continue;

            res *= nCr(total, x);

            if (res >= MAX)
                return MAX;

            total -= x;
        }

        return (int)res;
    }

    int nCr(int n, int r) {
        if (r > n)
            return 0;

        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;

            if (ans >= MAX)
                return MAX;
        }

        return (int)ans;
    }
};