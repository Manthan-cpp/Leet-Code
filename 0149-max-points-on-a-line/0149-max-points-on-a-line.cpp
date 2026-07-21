class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }
                mp[{dx, dy}]++;
                ans = max(ans, mp[{dx, dy}] + 1);
            }
        }
        return ans;
    }
};