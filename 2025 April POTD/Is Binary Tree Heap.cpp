// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        queue<Node*> q;
        q.push(tree);
        while(!q.empty()){
            int n = q.size();
            bool shouldWeHave = true;
            for(int i = 0; i < n; i++){
                Node* node = q.front();
                q.pop();
                
                if(node->left) {
                    if(!shouldWeHave || node->left->data > node->data)
                        return false;
                    else
                        q.push(node->left);
                    
                }
                else 
                    shouldWeHave = false;
                
                if(node->right) {
                    if(!shouldWeHave || node->right->data > node->data)
                        return false;
                    
                    else
                        q.push(node->right);
                
                }
                else 
                    shouldWeHave = false;
            }
        }
        return true;
    }
};
