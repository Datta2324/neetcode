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
    // Take it as a global variable or as a param pass by reference.
    int maxDiameter = 0;
    int maxHeight(TreeNode* root) {

        if(root == nullptr)
            return 0;

        int left = maxHeight(root->left);
        int right = maxHeight(root->right);

        maxDiameter = max(maxDiameter, left + right);
        return (1 + max(left,right));  
    }
    int diameterOfBinaryTree(TreeNode* root) {

        maxHeight(root);
        return maxDiameter; 
    }
};
