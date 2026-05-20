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
    int countNodes(TreeNode* root, int max)
    {
        if(root == nullptr)
            return 0;
        
        if(root->val >= max)
            count++;

        max = std::max(max, root->val);

        countNodes(root->left, max);
        countNodes(root->right, max);
        return count;

    }
    int goodNodes(TreeNode* root) {

        int max = -101;
        int count = 0;
        int ans = countNodes(root,max);
        return ans;
    }
};
