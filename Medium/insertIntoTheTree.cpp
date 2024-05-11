#include <iostream>
using namespace std;

struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
TreeNode* insertIntoBST(TreeNode* root, int val) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        TreeNode * new_node = new TreeNode(val);
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        if(val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        return root;
}
 void Inorder(TreeNode * root){
    if(root == nullptr){
        return;
    }
    cout << root->val << " ";
    Inorder(root->left);
    Inorder(root->right);
}
int main(){
    TreeNode * root = nullptr;
    root = insertIntoBST(root, 10);
    insertIntoBST(root, 2);
    insertIntoBST(root, 11);
    insertIntoBST(root, 5);
    insertIntoBST(root, 12);
    Inorder(root);
}
    