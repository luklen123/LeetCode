/*
 * LeetCode 940: Distinct Subsequences II
 * Link: https://leetcode.com/problems/distinct-subsequences-ii/
 * Approach: Dynamic Programming (Forward DP / Inclusion-Exclusion Principle)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        long long total = 0;

        vector<long long> endsWith(26, 0);
        
        for(char c : s) {
            int idx = c - 'a';
            
            long long added = (total + 1 - endsWith[idx] + mod) % mod;
            
            total = (total + added) % mod;
            endsWith[idx] = (endsWith[idx] + added) % mod;
        }

        return total;
    }
};

/*
 * TIME COMPLEXITY: O(n)
 * Where 'n' is the length of string 's'. We iterate through the string exactly once, 
 * and the operations inside the loop take constant time O(1).
 * 
 * SPACE COMPLEXITY: O(1)
 * We use a vector of fixed size 26 (for each lowercase English letter), 
 * which requires constant space regardless of the input string length.
 */
