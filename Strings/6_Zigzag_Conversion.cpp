// LeetCode 6
// Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == numRows - 1)
                goingDown = false;

            if (currRow == 0)
                goingDown = true;

            if (goingDown)
                currRow++;
            else
                currRow--;
        }

        string ans;

        for (int i = 0; i < numRows; i++)
            ans += rows[i];

        return ans;
    }
};
