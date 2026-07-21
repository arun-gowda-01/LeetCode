// LeetCode 921
// Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (!st.empty() && c == ')') {
                st.pop();
            } else if (st.empty() && c == ')') {
                count++;
            }
        }

        while (!st.empty()) {
            count++;
            st.pop();
        }

        return count;
    }
};
