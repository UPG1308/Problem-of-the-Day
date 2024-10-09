class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        Node *ans, *prev;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            Node *curH = new Node(mat[i][0]);
            Node *iter = curH;
            if (i == 0)
                ans = curH;
            for (int j = 1; j < m; j++) {
                Node *newNode = new Node(mat[i][j]);
                iter -> right = newNode;
                iter = iter -> right;
            }
            iter = curH;
            if (i != 0) {
                while (prev && iter) {
                    prev -> down = iter;
                    prev = prev -> right;
                    iter = iter -> right;
                }
            }
            prev = curH;
        }
        return ans;
    }
};
