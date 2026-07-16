// LeetCode 438
// Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = p.size(), m = s.size();

        if (n > m)
            return result;

        vector<int> freqP(26, 0), freqS(26, 0);

        for (char c : p)
            freqP[c - 'a']++;

        for (int i = 0; i < m; i++) {
            freqS[s[i] - 'a']++;

            if (i >= n)
                freqS[s[i - n] - 'a']--;

            if (freqP == freqS)
                result.push_back(i - n + 1);
        }

        return result;
    }
};
