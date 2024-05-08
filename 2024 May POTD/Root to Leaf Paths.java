class Solution {
    public static ArrayList<ArrayList<Integer>> Paths(Node root) {
        // code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        ArrayList<Integer> path = new ArrayList<>();
        path.add(root.data);
        dfs(root, ans, path);
        return ans;
        
    }
    public static void dfs(Node root, ArrayList<ArrayList<Integer>> ans, ArrayList<Integer> path){
        if(root == null) return;
        if(root.left == null && root.right == null){
            ans.add(new ArrayList<>(path));
            return;
        }
        if(root.left != null){
            path.add(root.left.data);
            dfs(root.left, ans, path);
            path.remove(path.size() - 1);
        }
        if(root.right != null){
            path.add(root.right.data);
            dfs(root.right, ans, path);
            path.remove(path.size() - 1);
        }
    }
}
        
