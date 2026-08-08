class Solution {
public:
    void solve(vector<int>& freq, int& count) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;

            freq[i]--;
            count++;

            solve(freq, count);

            freq[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);

        for (char c : tiles)
            freq[c - 'A']++;

        int count = 0;

        solve(freq, count);

        return count;
    }
};
