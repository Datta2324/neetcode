/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int count = 0;

    int kthSmallest(TreeNode* root, int k) 
    {
        // Base case:
        // Empty subtree has no answer
        if(root == nullptr)
            return -1;

        // First search in LEFT subtree
        int left = kthSmallest(root->left, k);

        // If left subtree already found kth smallest,
        // immediately return that answer upward
        if(left != -1)
            return left;

        // LEFT subtree finished
        // Now process current node
        count++;

        // If current node is kth visited node,
        // this is the answer
        if(count == k)
            return root->val;

        // Otherwise search in RIGHT subtree
        int right = kthSmallest(root->right, k);
        return right;
    }
};