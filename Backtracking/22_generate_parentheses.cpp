/*
 * LeetCode 22: Generate Parentheses
 * Link: https://leetcode.com/problems/generate-parentheses/
 * Approach: Backtracking
 */

class Solution {
public:
    void generate(int open, int close, int& n, string& act, vector<string>& res) {
        if (act.size() == 2 * n) {
            res.push_back(act);
            return;
        }

        if (open < n) {
            act.push_back('(');
            generate(open + 1, close, n, act, res);
            act.pop_back();
        }
        if (close < open) {
            act.push_back(')');
            generate(open, close + 1, n, act, res);
            act.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string curr = "";
        generate(0, 0, n, curr, results);

        return results;
    }
};

/*
 * TIME COMPLEXITY: O(4^n / sqrt(n))
 * Bounded by the n-th Catalan number, which represents the total number 
 * of valid parenthesis combinations.
 * 
 * SPACE COMPLEXITY: O(4^n / sqrt(n))
 * Space required to store all valid combinations in the 'results' vector. 
 * Strictly analyzing the auxiliary space (recursion call stack and the 
 * 'curr' string), it is O(n).
 */
