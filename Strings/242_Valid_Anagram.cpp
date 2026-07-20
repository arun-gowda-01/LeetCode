// LeetCode 242
// Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> freqS(26, 0), freqT(26, 0);

        for (int i = 0; i < t.size(); i++) {
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }

        return freqS == freqT;
    }
};
