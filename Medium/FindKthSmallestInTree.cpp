
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int count = 0;
int kthSmallest(TreeNode* root, int k) {
    if (root == nullptr)
        return -1; 
    
    int left = kthSmallest(root->left, k);
    
    if (left != -1)
        return left;
    count++;
    if (count == k)
        return root->val;
    
    return kthSmallest(root->right, k);
}
