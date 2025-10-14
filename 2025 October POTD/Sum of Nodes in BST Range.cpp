class Solution {
    int sum=0;
    public int nodeSum(Node root, int l, int r) {
     if(root==null) return sum; 
     nodeSum(root.left,l,r);
     if(root.data>=l&&root.data<=r) sum+=root.data;
     nodeSum(root.right,l,r);
     return sum;
    }
}
