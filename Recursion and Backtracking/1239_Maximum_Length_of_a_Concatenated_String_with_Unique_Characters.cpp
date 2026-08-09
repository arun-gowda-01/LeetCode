// LeetCode 1239
// Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:
    void solve(int index, vector<string>& arr, int currLen, int& ans, vector<bool>& used) {
        if (index == arr.size()) {
            ans = max(ans, currLen);
            return;
        }

        bool valid = true;
        vector<bool> current(26, false);

        for (char c : arr[index]) {
            if (used[c - 'a'] || current[c - 'a']) {
                valid = false;
                break;
            }
            current[c - 'a'] = true;
        }

        if (valid) {
            for (char c : arr[index])
                used[c - 'a'] = true;

            currLen += arr[index].size();

            solve(index + 1, arr, currLen, ans, used);

            currLen -= arr[index].size();

            for (char c : arr[index])
                used[c - 'a'] = false;
        }

        solve(index + 1, arr, currLen, ans, used);
    }

    int maxLength(vector<string>& arr) {
        int ans = 0;
        int currLen = 0;
        vector<bool> used(26, false);

        solve(0, arr, currLen, ans, used);

        return ans;
    }
};
