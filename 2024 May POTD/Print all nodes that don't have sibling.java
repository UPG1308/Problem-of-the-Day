class Tree
{
    ArrayList<Integer> noSibling(Node node)
    {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        dfs(node, list);
        if(list.size() == 0) { list.add(-1); return list;}
        Collections.sort(list);
        return list;
        
    }
    public void dfs(Node node, ArrayList<Integer> list){
        if(node == null) return;
        dfs(node.left, list);
        dfs(node.right, list);
        if((node.left == null && node.right != null)) list.add(node.right.data);
        if(node.right == null && node.left != null) list.add(node.left.data);
    }
}
