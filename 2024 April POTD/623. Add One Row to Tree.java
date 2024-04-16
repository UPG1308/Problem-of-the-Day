class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(root == null && depth > 1) return root;
        if(depth == 1){
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        }
        addOneRow(depth - 2, root, val);
        return root;
    }
    public void addOneRow(int level, TreeNode root, int val){
        if(root == null) return;
        if(level == 0){
            TreeNode node1 = new TreeNode(val);
            TreeNode node2 = new TreeNode(val);
            node1.left = root.left;
            node2.right = root.right;
            root.left = node1;
            root.right = node2;
            return;
        }

        if(root.left != null) addOneRow(level - 1, root.left, val);
        if(root.right != null) addOneRow(level - 1, root.right, val);
    }
}
