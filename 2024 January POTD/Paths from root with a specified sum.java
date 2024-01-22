class Solution
{
    public static ArrayList<ArrayList<Integer>> printPaths(Node root, int sum)
    {
        // code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> list = new ArrayList<>();
        dfs(root, ans, list, sum);
        return ans;
    }
    
    public static void dfs(Node node, ArrayList<ArrayList<Integer>> ans, ArrayList<Integer> list, int sum){
        if(node == null) return;
        list.add(node.data);
        if(sum - node.data == 0) ans.add(new ArrayList<>(list));
        dfs(node.left, ans, list, sum - node.data);
        dfs(node.right, ans, list, sum - node.data);
        list.remove(list.size() - 1);
    }
}
