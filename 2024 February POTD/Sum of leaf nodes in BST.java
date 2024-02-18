class Solution
{
    public static int sumOfLeafNodes(Node root)
    {
        // code here 
        if(root == null) return 0;
        if(root.left == null && root.right == null) return root.data;
        int left = sumOfLeafNodes(root.left);
        int right = sumOfLeafNodes(root.right);
        return left + right;
    }
}
