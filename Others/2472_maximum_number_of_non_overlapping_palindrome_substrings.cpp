/*
 * LeetCode 2472: Maximum Number of Non-overlapping Palindrome Substrings
 * Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
 * Approach: Greedy (Checking optimal minimal lengths k and k+1)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool check(int idx, int length, string& s) {
        if (idx + length > s.size()) return false;

        for (int i = 0; i < length / 2; i++) {
            if (s[idx + i] != s[idx + length - 1 - i]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (check(i, k, s)) {
                count++;
                i = i + k - 1;
            } else if (check(i, k + 1, s)) {
                count++;
                i = i + k;
            }
        }
        return count;
    }
};

/*
 * TIME COMPLEXITY: O(n * k)
 * Where 'n' is the length of string 's' and 'k' is the minimum required length of the palindrome.
 * We iterate through the string and for each index, we do at most two palindrome checks of length 'k' and 'k+1'.
 * 
 * SPACE COMPLEXITY: O(1)
 * We only use a few integer variables for counting and indexing. No additional data structures are allocated.
 */
