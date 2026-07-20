// LeetCode 5
// Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0, start = 0;

        for (int i = 0; i < n; i++) {
            // Odd-length palindrome
            int left = i, right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }

            // Even-length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};
