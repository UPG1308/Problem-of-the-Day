class Solution {
    int mx = 0;
    pair<int, bool> dfs(Node* root, int target){
        if(!root) return {0, false};
        auto [d, t] = dfs(root->left, target);
        auto [d2,t2] = dfs(root->right, target);
        if(root->data == target) {
            mx = max(d, d2);
            return{1, true};
        }
        if(!t && !t2){
            return {1+max(d, d2), false};
        }
        if(!t && t2){
            mx = max(mx, d+d2);
            return {d2+1, true};
        }
        if(t && !t2){
            mx = max(mx, d+d2);
            return {d+1, true};
        }
        throw "Kuch bhi";
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        dfs(root, target);
        return mx;
    }
};
