/*
 * LeetCode 1386: Cinema Seat Allocation
 * Link: https://leetcode.com/problems/cinema-seat-allocation/
 * Approach: Hashmap + bit operations
 */

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reserved) {
        unordered_map<int, int> row_masks;
        
        for (const auto& res : reserved) {
            int row = res[0];
            int col = res[1];
            row_masks[row] |= (1 << col);
        }
        
        int result = (n - row_masks.size()) * 2;
        
        int left   = 0b0000111100; // seats 2,3,4,5
        int middle = 0b0011110000; // seats 4,5,6,7
        int right  = 0b1111000000; // seats 6,7,8,9
        
        for (const auto& [row, mask] : row_masks) {
            if ((mask & (left | right)) == 0) {
                result += 2;
            } else if ((mask & left) == 0 || (mask & middle) == 0 || (mask & right) == 0) {
                result += 1;
            }
        }
        
        return result;
    }
};

/*
 * TIME COMPLEXITY: O(m)
 * Where 'm' is the length of array 'reserved'
 * 
 * SPACE COMPLEXITY: O(m)
 * For the hashmap storing masks for rows with at least one reservation. 
 * (Strictly speaking, O(min(n, m))).
 */
