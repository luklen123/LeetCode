/*
 * LeetCode 139: Word Break
 * Link: https://leetcode.com/problems/word-break/
 * Approach: Dynamic Programming (Bottom-Up)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);

        // Base case: empty string is always valid
        dp[n] = true;
        
        for (int i = n - 1; i >= 0; i--) {
            for (const auto& word : wordDict) {
                if (word.size() > n - i) continue;

                bool good = true;
                for (int k = 0; k < word.size(); k++) {
                    if (s[i + k] != word[k]) {
                        good = false;
                        break;
                    }
                }
                
                dp[i] = good && dp[i + word.size()];
                
                // If we found a valid sequence, no need to check other words for this index
                if (dp[i]) break; 
            }
        }

        return dp[0];
    }
};

/*
 * TIME COMPLEXITY: O(n * m * k)
 * Where 'n' is the length of string 's', 'm' is the number of words in 'wordDict', 
 * and 'k' is the maximum length of a word in 'wordDict'.
 * 
 * SPACE COMPLEXITY: O(n)
 * For the boolean DP array of size n + 1.
 */