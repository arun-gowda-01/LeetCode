// LeetCode 473
// Matchsticks to Square

class Solution {
public:
    bool solve(int index, vector<int>& matchsticks, vector<int>& sides, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > target)
                continue;

            sides[i] += matchsticks[index];

            if (solve(index + 1, matchsticks, sides, target))
                return true;

            sides[i] -= matchsticks[index];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides(4, 0);

        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (total % 4 != 0)
            return false;

        int target = total / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        return solve(0, matchsticks, sides, target);
    }
};
