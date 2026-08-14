/*
 * LeetCode 114: Flatten Binary Tree to Linked List
 * Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Approach: Iterative pointer manipulation (Morris Traversal logic)
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr) {
            // If there is a left child, we need to move it to the right
            if (curr->left) {
                // Find the rightmost node of the left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                
                // Rewire the connections
                rightmost->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node on the right
            curr = curr->right;
        }
    }
};

/*
 * TIME COMPLEXITY: O(n)
 * Each node is visited at most twice, resulting in linear time.
 * 
 * SPACE COMPLEXITY: O(1)
 * No recursion, no stacks, only a few pointers are used.
 */
