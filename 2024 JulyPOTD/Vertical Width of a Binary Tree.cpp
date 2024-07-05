class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int minWidth = 1000, maxWidth = -1000;
    void verticalWidth(Node* root, int width){
        if(root == nullptr) return;
        verticalWidth(root -> left, width - 1);
        verticalWidth(root -> right, width + 1);
        minWidth = min(minWidth, width);
        maxWidth = max(maxWidth, width);
    }
    int verticalWidth(Node* root) {
        // code here
        if(root == nullptr) return 0;
        verticalWidth(root, 0);
        return maxWidth - minWidth + 1;
    }
};
