
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), r = nums, nr(n);
        iota(sa.begin(), sa.end(), 0);

        for (int k = 1; ; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (r[a] != r[b])
                    return r[a] < r[b];

                int x = (a + k < n) ? r[a + k] : -1;
                int y = (b + k < n) ? r[b + k] : -1;

                return x < y;
            });

            nr[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                int a1 = r[a];
                int b1 = r[b];

                int a2 = (a + k < n) ? r[a + k] : -1;
                int b2 = (b + k < n) ? r[b + k] : -1;

                nr[b] = nr[a] + (a1 != b1 || a2 != b2);
            }

            r.swap(nr);

            if (r[sa.back()] == n - 1)
                break;
        }

        vector<int> rank(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int pos = rank[i];

            if (pos == 0) {
                h = 0;
                continue;
            }

            int j = sa[pos - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[pos] = h;

            if (h > 0)
                h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int mx = 0;

            if (i > 0)
                mx = max(mx, lcp[i]);

            if (i + 1 < n)
                mx = max(mx, lcp[i + 1]);

            int remaining = n - sa[i];

            if (mx < remaining)
                ans = min(ans, mx + 1);
        }

        return ans;
    }
};
