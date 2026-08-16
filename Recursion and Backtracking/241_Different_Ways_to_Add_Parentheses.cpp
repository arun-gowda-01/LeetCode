// LeetCode 241
// Different Ways to Add Parentheses

class Solution {
public:
    vector<int> solve(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' ||
                expression[i] == '-' ||
                expression[i] == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftResults = solve(left);
                vector<int> rightResults = solve(right);

                for (int x : leftResults) {
                    for (int y : rightResults) {
                        if (expression[i] == '+')
                            ans.push_back(x + y);
                        else if (expression[i] == '-')
                            ans.push_back(x - y);
                        else
                            ans.push_back(x * y);
                    }
                }
            }
        }

        if (ans.empty())
            ans.push_back(stoi(expression));

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
