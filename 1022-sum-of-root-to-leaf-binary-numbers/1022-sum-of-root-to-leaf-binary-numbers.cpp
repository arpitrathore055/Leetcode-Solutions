
class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (!root) return 0;

        // Build current binary number
        current = (current << 1) | root->val;

        // If leaf node, return the number formed
        if (!root->left && !root->right)
            return current;

        // Otherwise sum left and right
        return dfs(root->left, current) + 
               dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};