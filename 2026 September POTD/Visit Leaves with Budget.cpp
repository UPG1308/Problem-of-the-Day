/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void helper(Node *root, int k, vector<int> &value){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            value.push_back(k);
            return;
        }
        helper(root -> left, k + 1, value);
        helper(root -> right, k + 1, value);
        return;
    }
    
    int getCount(Node *root, int k) {
        // code here
        vector<int> value;
        helper(root, 1, value);
        sort(value.begin(), value.end());
        int count = 0, sum = 0;
        for(int i: value) {
            sum += i;
            if(sum <= k) count++;
        }
        return count;
    }
};
