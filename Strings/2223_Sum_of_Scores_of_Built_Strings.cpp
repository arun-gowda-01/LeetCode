// LeetCode 2223
// Sum of Scores of Built Strings

class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> z(n, 0);

        int left = 0, right = 0;

        for (int i = 1; i < n; i++) {
            if (i <= right)
                z[i] = min(right - i + 1, z[i - left]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }

        long long ans = n;

        for (int i = 1; i < n; i++)
            ans += z[i];

        return ans;
    }
};
