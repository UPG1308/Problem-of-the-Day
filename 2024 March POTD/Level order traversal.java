class Solution
{
    //Function to return the level order traversal of a tree.
    static ArrayList <Integer> levelOrder(Node root) 
    {
        ArrayList<Integer> list = new ArrayList<>();
        Deque<Node> q = new ArrayDeque<>();
        q.offerLast(root);
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node node = q.pollFirst();
                list.add(node.data);
                if(node.left != null) q.offerLast(node.left);
                if(node.right != null) q.offerLast(node.right);
            }
        }
        return list;
    }
}
