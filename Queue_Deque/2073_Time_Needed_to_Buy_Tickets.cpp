// LeetCode 2073
// Time Needed to Buy Tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        for (int i = 0; i < tickets.size(); i++)
            q.push(i);

        int time = 0;

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            tickets[person]--;
            time++;

            if (tickets[person] == 0) {
                if (person == k)
                    return time;
            }
            else {
                q.push(person);
            }
        }

        return time;
    }
};
