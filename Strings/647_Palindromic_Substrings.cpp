// LeetCode 647
// Palindromic Substrings

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes
            int left = i, right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            // Even-length palindromes
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};
