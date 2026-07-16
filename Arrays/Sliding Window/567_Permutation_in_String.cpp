// LeetCode 567
// Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false;

        vector<int> freqs1(128, 0), freqs2(128, 0);

        for (char c : s1)
            freqs1[c]++;

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            freqs2[s2[right]]++;

            while (right - left + 1 > s1.size()) {
                freqs2[s2[left]]--;
                left++;
            }

            if (freqs1 == freqs2)
                return true;
        }

        return false;
    }
};
