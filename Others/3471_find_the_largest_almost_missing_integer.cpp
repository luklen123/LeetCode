/*
 * LeetCode 3471: Find the Largest Almost Missing Integer
 * Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
 * Approach: Custom (Observation based on sliding window overlaps)
 */

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n){
            int max_val = -1;
            for(int i=0; i<n; i++) max_val = max(max_val, nums[i]);
            return max_val;
        }

        int occ[51] = {}; // size based on task constraints
        for(int i=0; i<n; i++) occ[nums[i]]++;

        if(k == 1){
            for(int i=50; i>=0; i--) if(occ[i] == 1) return i;
        } else {
            return max((occ[nums[0]] > 1 ? -1 : nums[0]), (occ[nums[n - 1]] > 1 ? -1 : nums[n - 1]));
        } 

        return -1;
    }
};

/*
 * TIME COMPLEXITY: O(n)
 * Where 'n' is the length of array 'nums'. We iterate through the array a constant number of times.
 * 
 * SPACE COMPLEXITY: O(1)
 * We use a fixed-size frequency array of size 51, regardless of the input size 'n'.
 */
