class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int> inorder;
        solve(root,inorder);
        if(k<=inorder.size()) return inorder[k-1];
        else return -1;
    }
    void solve(Node* node, vector<int> &inorder){
        if(node==nullptr) return;
        solve(node->left, inorder);
        inorder.push_back(node->data);
        solve(node->right, inorder);
    }
};
