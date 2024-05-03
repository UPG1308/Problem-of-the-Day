class Tree
{
     // Recursive function to print right view of a binary tree.
     ArrayList<Integer> Kdistance(Node root, int k)
     {
          // Your code here
          ArrayList<Integer> list = new ArrayList<>();
          dfs(root, k, list);
          return list;
     }
     public void dfs(Node root, int k, ArrayList<Integer> list){
         if(root == null) return;
         if(k == 0) {list.add(root.data); return;}
         
         if(root.left != null) dfs(root.left, k - 1, list);
         if(root.right != null) dfs(root.right, k - 1, list);
     }
}
