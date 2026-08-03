// LeetCode 150
// Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long second = st.top();
                st.pop();

                long long first = st.top();
                st.pop();

                if (token == "+")
                    st.push(first + second);
                else if (token == "-")
                    st.push(first - second);
                else if (token == "*")
                    st.push(first * second);
                else
                    st.push(first / second);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
