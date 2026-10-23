class Solution {
public:

    void dfsTraversal(TreeNode* root, int& height, bool exploreLeft) {

        if(root == nullptr){
            return;
        }

        height++;

        if(exploreLeft){
            dfsTraversal(root->left, height, exploreLeft);
        }
        else{
            dfsTraversal(root->right, height, exploreLeft);
        }
    }

    int countNodes(TreeNode* root) {

        if(root == nullptr){
            return 0;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        dfsTraversal(root, leftHeight, true);
        dfsTraversal(root, rightHeight, false);

        if(leftHeight == rightHeight){
            return static_cast<int>((1LL << leftHeight) - 1);
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};