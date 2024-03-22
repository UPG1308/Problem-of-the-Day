class Tree {
    public static ArrayList <Integer> diagonalSum(Node root) 
    {
        ArrayList <Integer> arr = new ArrayList <Integer>();
        HashMap<Integer, Integer> map=new HashMap<>();
        solve(root, root.data, 0, map);
        for(Integer value :map.values()){
            arr.add(value);
        }
        return arr;
    }
     public static void solve(Node root, int sum, int level,  HashMap<Integer, Integer> map)
    {
        if(root==null) return ;
        map.put(level, map.getOrDefault(level,0)+root.data);
        
        solve(root.right, root.data, level, map);
        solve(root.left, root.data, level+1, map);
    }
}
