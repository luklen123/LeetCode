/*
 * LeetCode 3069: Distribute Elements Into Two Arrays I
 * Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
 * Approach: Custom 
 */

class Solution {
public:
    vector<int> resultArray(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);

        res[0] = nums[0];
        res[n - 1] = nums[1];
        int p1 = 1;
        int p2 = n - 2;

        for(int i=2; i<n; i++){
            if(res[p1 - 1] > res[p2 + 1]) res[p1++] = nums[i];
            else res[p2--] = nums[i];
        }
        reverse(res.begin() + p1, res.end());
        
        return res;
    }
};

/*
 * TIME COMPLEXITY: O(n)
 * Where 'n' is the length of array 'nums'. We iterate through the array a constant number of times.
 * 
 * SPACE COMPLEXITY: O(1) auxiliary space
 * We only use O(n) space for the returned 'res' array, and O(1) extra space for the pointers.
 */
