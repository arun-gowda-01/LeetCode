// LeetCode 884
// Uncommon Words from Two Sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        stringstream ss1(s1);
        string word;

        while (ss1 >> word)
            freq[word]++;

        stringstream ss2(s2);

        while (ss2 >> word)
            freq[word]++;

        vector<string> ans;

        for (auto it : freq) {
            if (it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};
