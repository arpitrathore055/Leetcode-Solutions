class Solution {
public:

    void dfsTraversal(TreeNode* root, TreeNode* parent, int key,
                      TreeNode*& targetNodeParent, TreeNode*& targetNode){

        if(root == nullptr){
            return;
        }

        if(root->val == key){
            targetNodeParent = parent;
            targetNode = root;
            return;
        }
        else if(key < root->val){
            dfsTraversal(root->left, root, key,
                         targetNodeParent, targetNode);
        }
        else{
            dfsTraversal(root->right, root, key,
                         targetNodeParent, targetNode);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key){

        if(root == nullptr){
            return nullptr;
        }

        TreeNode* targetNodeParent = nullptr;
        TreeNode* targetNode = nullptr;

        dfsTraversal(root, nullptr, key,
                     targetNodeParent, targetNode);

        if(targetNode == nullptr){
            return root;
        }

        // 1. Target node has no children.
        if(targetNode->left == nullptr &&
           targetNode->right == nullptr){

            if(targetNodeParent == nullptr){
                root = nullptr;
            }
            else if(targetNodeParent->left == targetNode){
                targetNodeParent->left = nullptr;
            }
            else{
                targetNodeParent->right = nullptr;
            }

            delete targetNode;
            return root;
        }

        // 2. Target node has exactly one child.
        if(targetNode->left == nullptr ||
           targetNode->right == nullptr){

            TreeNode* replacement = (targetNode->left != nullptr)
                                    ? targetNode->left
                                    : targetNode->right;

            if(targetNodeParent == nullptr){
                root = replacement;
            }
            else if(targetNodeParent->left == targetNode){
                targetNodeParent->left = replacement;
            }
            else{
                targetNodeParent->right = replacement;
            }

            delete targetNode;
            return root;
        }

        // 3. Target node has both children.
        TreeNode* nextCandidateParent = targetNode;
        TreeNode* nextCandidate = targetNode->right;

        // Find the smallest node in the right subtree.
        while(nextCandidate->left != nullptr){
            nextCandidateParent = nextCandidate;
            nextCandidate = nextCandidate->left;
        }

        targetNode->val = nextCandidate->val;

        // Successor has no left child, but may have a right child.
        if(nextCandidateParent->left == nextCandidate){
            nextCandidateParent->left = nextCandidate->right;
        }
        else{
            nextCandidateParent->right = nextCandidate->right;
        }

        delete nextCandidate;
        return root;
    }
};