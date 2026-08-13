// LeetCode 1306
// Jump Game III

class Solution {
public:
    bool solve(int index, vector<int>& arr, vector<int>& visited) {
        if (index < 0 || index >= arr.size())
            return false;

        if (arr[index] == 0)
            return true;

        if (visited[index])
            return false;

        visited[index] = 1;

        bool found = solve(index + arr[index], arr, visited) ||
                     solve(index - arr[index], arr, visited);

        visited[index] = 0;

        return found;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);

        return solve(start, arr, visited);
    }
};
