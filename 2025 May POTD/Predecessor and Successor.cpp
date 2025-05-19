class Solution {
  public:
    
    void dfs(Node* root, vector<Node*> &path){
        
        if(root -> left != NULL) dfs(root -> left, path);
        path.push_back(root);
        if(root -> right != NULL) dfs(root -> right, path);
    }
        
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> path;
        dfs(root, path);
        
        vector<Node*> ans{NULL, NULL};
        for(int i = 0; i < path.size(); ++i){
            if(path[i] -> data < key) ans[0] = path[i];
            if(path[i] -> data > key && ans[1] == NULL) ans[1] = path[i];
        }
        return ans;
    }
};
