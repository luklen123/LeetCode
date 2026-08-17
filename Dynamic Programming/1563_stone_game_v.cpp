/*
 * LeetCode 1563. Stone Game V
 * Link: https://leetcode.com/problems/stone-game-v/
 * Approach: Dynamic Programming (Top-Down with memorization)
 */

class Solution {
public:

    int game(int l, int r, vector<int>& prefix, vector<vector<int>>& dp){
        if(dp[l][r] != -1) return dp[l][r];

        if(l == r) return dp[l][r] = 0;

        int result = 0;
        for(int i=l; i<r; i++){
            int sum_l = prefix[i] - prefix[l - 1];
            int sum_r = prefix[r] - prefix[i]; 
            int score = 0;

            if(sum_l < sum_r){
                score = sum_l + game(l, i, prefix, dp);
            } else if(sum_r < sum_l){
                score = sum_r + game(i + 1, r, prefix, dp);
            } else {
                score = sum_l + max(game(l, i, prefix, dp), game(i + 1, r, prefix, dp));
            }
            result = max(result, score);
        }

        return dp[l][r] = result;
    }

    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n+1, 0);
        prefix[0] = 0;
        for(int i=1; i<=n; i++) prefix[i] = prefix[i - 1] + stones[i - 1];

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        return game(1, n, prefix, dp);
    }
};

/*
 * TIME COMPLEXITY: O(n^3)
 * Where 'n' is the length of array stoneValue.
 * 
 * SPACE COMPLEXITY: O(n^2)
 * For the int DP array of size (n + 1) * (n + 1) .
 */
