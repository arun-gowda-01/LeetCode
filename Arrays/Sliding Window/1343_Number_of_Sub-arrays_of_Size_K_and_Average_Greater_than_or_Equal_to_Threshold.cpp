// LeetCode 1343
// Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0, count = 0;
        long long sum = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            if (right - left + 1 == k) {
                if ((double)sum / k >= threshold)
                    count++;

                sum -= arr[left];
                left++;
            }
        }

        return count;
    }
};
