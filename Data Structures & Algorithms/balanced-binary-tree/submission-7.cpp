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
    int height(TreeNode *root, bool &ans)
    {
        if(root == nullptr)
            return 0;
        int left = height(root->left,ans);
        // Can run even without this but just to early exit if left subtree itself is not balanced
        if(ans == false)
            return -1;
        int right = height(root->right,ans);
        if(abs(left - right) > 1)
            ans = false;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        bool ans = true;
        height(root,ans);

        return ans;
        
    }
};
