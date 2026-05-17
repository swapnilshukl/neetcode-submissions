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
    int maxPath(TreeNode* node, int &maxi){
        if(!node) return 0;
        int ls = max(0,maxPath(node->left, maxi));
        int rs = max(0,maxPath(node->right, maxi));

        maxi = max(maxi, ls+rs+node->val);
        return (node->val + max(ls,rs));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int path = maxPath(root,maxi);
        return maxi;
    }
};
