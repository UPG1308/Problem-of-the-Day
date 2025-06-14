class Solution {
  public:
    bool isSymmetric(Node* root1, Node* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL || root1 -> data != root2 -> data) return false;
        
        if(!isSymmetric(root1 -> left, root2 -> right)) return false;
        if(!isSymmetric(root1 -> right, root2 -> left)) return false;
        return true;
    }
  
    bool isSymmetric(Node* root) {
        // Code here
        if(root == NULL) return true;
        return isSymmetric(root -> left, root -> right);
    }
};
