// LeetCode 907
// Sum of Subarray Minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        long long res = 0;
        const int MOD = 1e9 + 7;

        // Distance to previous smaller or equal element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Distance to next strictly smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            res = (res +
                   (long long)arr[i] * left[i] % MOD * right[i] % MOD)
                  % MOD;
        }

        return res;
    }
};
