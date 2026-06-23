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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& mpp,
                    int inStart,int inEnd, int preStart,int preEnd)
    {
        //Base case should set nullptrs
        if((preStart > preEnd )|| (inStart > inEnd))
            return nullptr;

        // CreateNode
        TreeNode* node = new TreeNode(preorder[preStart]);
        //Find left and right partition and root
        int rootIn = mpp[node->val];

        // Find the next leftRoot and RightRoot
        int leftRoot = preStart + 1;
        int numsLeft = rootIn - inStart;

        node->left  = build(preorder,inorder,mpp,inStart,rootIn - 1,preStart + 1 , preStart + numsLeft);
        node->right = build(preorder,inorder,mpp,rootIn + 1 ,inEnd,preStart + numsLeft +1,preEnd);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hash;

        for(int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;

        TreeNode* root = build(preorder,inorder,hash,0 , inorder.size() - 1, 0 , preorder.size() -1);
        return root;
    }
};
