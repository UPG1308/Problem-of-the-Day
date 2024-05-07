class Tree
{
    public ArrayList<Integer> reverseLevelOrder(Node node) 
    {
        // code here
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        ArrayList<Integer> res=new ArrayList<Integer>();
        
        while(!q.isEmpty()){
            Node tmp=q.remove();
            res.add(tmp.data);
            if(tmp.right!=null){
                q.add(tmp.right);
            }
            if(tmp.left!=null){
                q.add(tmp.left);
            }
        }
        Collections.reverse(res);
        return res;
    }
}
