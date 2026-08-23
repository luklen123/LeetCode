/*
 * LeetCode 1927: Sum Game
 * Link: https://leetcode.com/problems/sum-game/
 * Approach: Math / Game Theory
 */

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int l = 0;
        int l_sum = 0;
        for(int i=0; i<n/2; i++){
            if(num[i] == '?') l++;
            else l_sum += num[i] - '0';
        } 

        int r = 0;
        int r_sum = 0;
        for(int i=n/2; i<n; i++){
            if(num[i] == '?') r++;
            else r_sum += num[i] - '0';
        }

        if((l + r) % 2 == 1) return true;
        if((l / 2) * 9 + l_sum == (r / 2) * 9 + r_sum) return false;
        return true;
    }
};

/*
 * TIME COMPLEXITY: O(n)
 * Where 'n' is the length of string 'num'. We iterate through the string a constant number of times.
 * 
 * SPACE COMPLEXITY: O(1)
 * We only use a few integer variables, so the space used is constant.
 */
