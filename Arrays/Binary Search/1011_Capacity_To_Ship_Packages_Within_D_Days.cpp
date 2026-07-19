// LeetCode 1011
// Capacity To Ship Packages Within D Days

class Solution {
public:
    bool isValid(vector<int>& weights, int minCap, int days) {
        int daysTaken = 1;
        int sumWeight = 0;

        for (int weight : weights) {
            sumWeight += weight;

            if (sumWeight > minCap) {
                sumWeight = weight;
                daysTaken++;
            }
        }

        return daysTaken <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isValid(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
