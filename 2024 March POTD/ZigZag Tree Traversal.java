class GFG
{
    int level(Node root){
        if(root == null)return 0;
        return 1+Math.max(level(root.left),level(root.right));
    }
    void pre(Node root,ArrayList<Integer> list,int i){
        if(root == null)return;
        if(i == 1)list.add(root.data);
        pre(root.left,list,i-1);
        pre(root.right,list,i-1);
    }
    void post(Node root,ArrayList<Integer> list,int i){
        if(root == null)return;
        if(i == 1)list.add(root.data);
        post(root.right,list,i-1);
        post(root.left,list,i-1);
    }
    //Function to store the zig zag order traversal of tree in a list.
	ArrayList<Integer> zigZagTraversal(Node root)
	{
	    //Add your code here.
	    ArrayList<Integer> list = new ArrayList<>();
	    int n = level(root);
	    for(int i = 1; i <= n ; i++){
	        if(i%2 != 0){
	            pre(root,list,i);
	        }else{
	            post(root,list,i);
	        }
	    }
	    return list;
	}
}
