// LeetCode 526
// Beautiful Arrangement

class Solution {
public:
    void solve(int n, vector<int>& perm, vector<bool>& used, int& count) {
        if (perm.size() == n) {
            count++;
            return;
        }

        int position = perm.size() + 1;

        for (int i = 1; i <= n; i++) {
            if (used[i])
                continue;

            if (position % i != 0 && i % position != 0)
                continue;

            perm.push_back(i);
            used[i] = true;

            solve(n, perm, used, count);

            used[i] = false;
            perm.pop_back();
        }
    }

    int countArrangement(int n) {
        int count = 0;
        vector<int> perm;
        vector<bool> used(n + 1, false);

        solve(n, perm, used, count);

        return count;
    }
};
