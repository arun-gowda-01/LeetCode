// LeetCode 1186
// Maximum Subarray Sum with One Deletion

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int keep = arr[0];
        int del = 0;
        int result = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevKeep = keep;

            del = max(del + arr[i], prevKeep);
            keep = max(arr[i], prevKeep + arr[i]);

            result = max(result, max(keep, del));
        }

        return result;
    }
};
