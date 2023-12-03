
class Solution
{
    public static void traverse(Node root, Set<Integer> arr){
        if(root == null) return ;
        traverse(root.left,arr);
        arr.add(root.data);
        traverse(root.right,arr);
    }
    public static int countPairs(Node root1, Node root2, int x)
    {
        Set<Integer> arr = new HashSet<>();
        traverse(root1,arr);
        return count(root2,arr,x);
    }
    public static int count(Node root, Set<Integer> set,int x){
        int cnt = 0;
        if(root == null) return cnt;
        
        if(set.contains(x-root.data)){
            cnt++;
        }
        
        return cnt+count(root.left,set,x)+count(root.right,set,x);
    }
}
