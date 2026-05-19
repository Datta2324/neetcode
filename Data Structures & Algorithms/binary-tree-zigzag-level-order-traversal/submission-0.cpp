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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<vector<int>> ans;

        if(root)
            q.push(root);
        
        int count = 0;
        
        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();

            while(size)
            {
                TreeNode* pos = q.front();
                temp.push_back(pos->val);

                if(pos->left)
                    q.push(pos->left);
                if(pos->right)
                    q.push(pos->right);

                q.pop();
                size--;
            }
            count++;
            //Alternate Zig Zag
            if(!(count & 1))
                reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};