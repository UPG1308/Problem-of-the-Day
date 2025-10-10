class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        deque<Node*> q;
        q.push_back(root);
        bool flag = false;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                if(flag) {
                    Node* node = q.back();
                    q.pop_back();
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                    ans.push_back(node->data);
                } else {
                    Node* node = q.front();
                    q.pop_front();
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                    ans.push_back(node->data);
                }
                size--;
            }
            flag = !flag;
        }
        return ans;
    }
};
