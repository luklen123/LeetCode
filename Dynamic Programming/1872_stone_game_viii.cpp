/*
 * LeetCode 1872: Stone Game VIII
 * Link: https://leetcode.com/problems/stone-game-viii/
 * Approach: Dynamic Programming (Bottom-Up)
 */

class Solution {
public:

    int stoneGameVIII(vector<int>& stones){
        int n = stones.size();

        int sum = 0;
        for(int i=0; i<n; i++) sum += stones[i];

        int prev = sum;
        for(int i=n-2; i>=1; i--){
            sum -= stones[i + 1];
            prev = max(sum - prev, prev);
        } 

        return prev; 
    }
    
};

/*
 * TIME COMPLEXITY: O(n)
 * Where 'n' is the length of array 'stones'
 * 
 * SPACE COMPLEXITY: O(1)
 * No extra space needed
 */
