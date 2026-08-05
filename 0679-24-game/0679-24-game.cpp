class Solution {
public:
    bool solve(vector<double>& a) {
        if (a.size() == 1)
            return fabs(a[0] - 24.0) < 1e-6;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> b;
                for (int k = 0; k < n; k++)
                    if (k != i && k != j)
                        b.push_back(a[k]);
                for (int op = 0; op < 4; op++) {
                    if ((op == 0 || op == 2) && i > j) continue;
                    if (op == 0) b.push_back(a[i] + a[j]);
                    else if (op == 1) b.push_back(a[i] - a[j]);
                    else if (op == 2) b.push_back(a[i] * a[j]);
                    else {
                        if (fabs(a[j]) < 1e-6) continue;
                        b.push_back(a[i] / a[j]);
                    }
                    if (solve(b)) return true;
                    b.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> a;
        for (int x : cards) a.push_back(x);
        return solve(a);
    }
};