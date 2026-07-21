// LeetCode 496
// Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                nge[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(nge[x]);
        }

        return ans;
    }
};
