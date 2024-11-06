class Solution {
  public:
    void treePathSum(Node* root, int& val, int& sum){
        if(root == NULL) return;
        val = val * 10 + root -> data;
        if(root -> left == NULL && root -> right == NULL){
            sum += val;
        }
        treePathSum(root -> left, val, sum);
        treePathSum(root -> right, val, sum);
        val -= root -> data;
        val /= 10;
    }
    int treePathsSum(Node *root) {
        // code here.
        int sum = 0, val = 0;
        treePathSum(root, val, sum);
        return sum;
    }
};
