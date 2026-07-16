// LeetCode 76
// Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        if (t.size() > s.size())
            return "";

        vector<int> freq(128, 0);

        for (char c : t)
            freq[c]++;

        int left = 0, start = 0;
        int minLen = INT_MAX;
        int count = t.size();

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]]-- > 0)
                count--;

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                if (freq[s[left]]++ == 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
