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

    vector<int> ans;

    void rec(TreeNode* n){
        if(n == NULL)
            return ;
        ans.push_back(n->val);
        rec(n->left);
        rec(n->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        rec(root);
        return ans;
    }
};