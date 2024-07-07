class Solution {
  public:
    // Function should return all the ancestor of the target node
    vector<int>ans;
    bool solve(Node* root, int t){
        if(root==NULL) return 0;
        if(root->data==t) return 1;
        bool lft=solve(root->left, t);
        bool rgt=solve(root->right, t);
        if(lft||rgt){
            ans.push_back(root->data);
            return 1;
        }
        return 0;
    }
    
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        //vector<int>ans;
        solve(root, target);
        return ans;
    }
};
