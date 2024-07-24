class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root, int leftBound, int rightBound){
        if(root == NULL) return true;
        return (root -> data >= leftBound and root -> data <= rightBound) and isBST(root -> left, leftBound, root -> data - 1) and isBST(root -> right, root -> data, rightBound);
    }
    
    bool isBST(Node* root) {
        // Your code here
        return isBST(root, -1e6, 1e6);
    }
};
