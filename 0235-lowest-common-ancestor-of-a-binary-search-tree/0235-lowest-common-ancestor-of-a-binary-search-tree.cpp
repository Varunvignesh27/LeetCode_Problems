/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool dfs(TreeNode* u,TreeNode* x,stack<TreeNode*>& s){
        
        s.push(u);

        if(u == x)
            return true;

        if(u->left != NULL)
            if(dfs(u->left,x,s))
                return true;

        if(u->right != NULL)
            if(dfs(u->right,x,s))
                return true;

        s.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sp,sq;
        TreeNode* a;

        if(dfs(root,p,sp) && dfs(root,q,sq)){
            while(sp.size() < sq.size()){
                sq.pop();
            }
            while(sp.size() > sq.size()){
                sp.pop();
            }

            while(!sp.empty() || sq.empty()){
                if(sp.top() == sq.top()){
                    a = sp.top();
                    break;
                }
                sp.pop();
                sq.pop();
            }
        }

        return a;
    }
};