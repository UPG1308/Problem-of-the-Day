class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isLeaf(Node* root){
        if(!root)
            return false;
        if(root->left || root->right)
            return false;
        return true;
    }
    
    
    pair<int,int> isBST_helper(Node* root){
        if(!root)
            return {INT_MAX , INT_MIN};
        if(isLeaf(root))
            return {root->data , root->data};
        
        pair<int,int> l = isBST_helper(root->left);
        pair<int,int> r = isBST_helper(root->right);
        
        if((root->data <= l.second) || (root->data >= r.first))
            return {INT_MIN , INT_MAX};
        
        return {min({l.first,root->data,r.first}) , max({l.second,root->data,r.second})};
            
    }
    
    bool isBST(Node* root) {
        // Your code here
        pair<int,int> p = isBST_helper(root);
        if((p.first == INT_MIN) || (p.second == INT_MAX))
            return false;
        return true;
        
    }
};
