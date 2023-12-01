class Solution
{
    public static boolean isDeadEnd(Node root)
    {
        //Add your code here.
        return helper(root,0,Integer.MAX_VALUE);
    }
    public static boolean helper(Node n,int min,int max){
        if(n == null)   return false;
        if(n.left==null && n.right==null){
            if(n.data-min>1 || max-n.data>1)
                return false;
            return true;
        }
        return helper(n.left,min,n.data) ||
               helper(n.right,n.data,max);
    }
}

