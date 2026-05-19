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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<vector<int>>ans;
        
        if(!root)
            return ans;

        q.push(root);
        
        while(!q.empty())
        {
            // Take size of the queue to know how many nodes in current level
            int size = q.size();
            std::vector<int> temp;
            for(int i = 0; i < size; i++)
            {
                TreeNode* pos = q.front();
                temp.push_back(pos->val);
                if(pos->left)
                    q.push(pos->left);
                if(pos->right)
                    q.push(pos->right);
                q.pop();
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};