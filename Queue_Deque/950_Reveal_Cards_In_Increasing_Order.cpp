// LeetCode 950
// Reveal Cards In Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        queue<int> q;

        for (int i = 0; i < deck.size(); i++)
            q.push(i);

        vector<int> ans(deck.size());

        for (int card : deck) {
            int position = q.front();
            q.pop();

            ans[position] = card;

            if (!q.empty()) {
                int next = q.front();
                q.pop();
                q.push(next);
            }
        }

        return ans;
    }
};
