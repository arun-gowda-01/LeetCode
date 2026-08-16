// LeetCode 842
// Split Array into Fibonacci Sequence

class Solution {
public:
    bool solve(int index, string& num, vector<int>& sequence) {
        if (index == num.size())
            return sequence.size() >= 3;

        long long value = 0;

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                break;

            value = value * 10 + (num[i] - '0');

            if (value > INT_MAX)
                break;

            if (sequence.size() >= 2) {
                long long sum = (long long)sequence[sequence.size() - 1] +
                                sequence[sequence.size() - 2];

                if (value < sum)
                    continue;

                if (value > sum)
                    break;
            }

            sequence.push_back((int)value);

            if (solve(i + 1, num, sequence))
                return true;

            sequence.pop_back();
        }

        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        vector<int> sequence;

        solve(0, num, sequence);

        return sequence;
    }
};
