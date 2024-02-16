class Solution {
    Node ans,temp;
    public Node flattenBST(Node root) {
        ans = new Node(0);
        temp = ans;
        solve(root);
        return ans.right;
    }
    
    public void solve(Node root){
        if(root == null)return;
        solve(root.left);
        temp.right = new Node(root.data);
        temp = temp.right;
        solve(root.right);
    }
}
