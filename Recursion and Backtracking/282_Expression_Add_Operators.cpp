// LeetCode 282
// Expression Add Operators

class Solution {
public:
    void solve(int index, string& num, int target, string& expression,
               long long currentValue, long long previousValue,
               vector<string>& ans) {
        if (index == num.size()) {
            if (currentValue == target)
                ans.push_back(expression);
            return;
        }

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                break;

            string current = num.substr(index, i - index + 1);
            long long value = stoll(current);

            if (index == 0) {
                expression += current;

                solve(i + 1, num, target, expression, value, value, ans);

                expression.erase(expression.size() - current.size());
            } else {
                expression += "+" + current;
                solve(i + 1, num, target, expression,
                      currentValue + value, value, ans);
                expression.erase(expression.size() - current.size() - 1);

                expression += "-" + current;
                solve(i + 1, num, target, expression,
                      currentValue - value, -value, ans);
                expression.erase(expression.size() - current.size() - 1);

                expression += "*" + current;
                solve(i + 1, num, target, expression,
                      currentValue - previousValue + previousValue * value,
                      previousValue * value, ans);
                expression.erase(expression.size() - current.size() - 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string expression;

        solve(0, num, target, expression, 0, 0, ans);

        return ans;
    }
};
