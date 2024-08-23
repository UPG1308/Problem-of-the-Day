vector<int> lft;
unordered_map<int,int> mp;
void dfs(Node* root,int height){
    if(root == nullptr){
        return;
    }
    if(mp.find(height) == mp.end()){
        mp[height]= 1;
        lft.push_back(root->data);
    }
    dfs(root->left,height+1);
    dfs(root->right,height+1);
}
vector<int> leftView(Node *root)
{
    lft.clear();
    mp.clear();
    dfs(root,0);
    return lft;
}
